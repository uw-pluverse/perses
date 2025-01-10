use rustc_data_structures :: fx :: FxHashSet ;
use rustc_data_structures :: temp_dir :: MaybeTempDir ;
use rustc_fs_util :: fix_windows_verbatim_for_gcc ;
use rustc_hir :: def_id :: CrateNum ;
use rustc_middle :: middle :: cstore :: { EncodedMetadata , LibSource , NativeLib } ;
use rustc_middle :: middle :: dependency_format :: Linkage ;
use rustc_session :: config :: { self , CFGuard , CrateType , DebugInfo } ;
use rustc_session :: config :: { OutputFilenames , OutputType , PrintRequest , SanitizerSet } ;
use rustc_session :: output :: { check_file_is_writeable , invalid_output_for_target , out_filename } ;
use rustc_session :: search_paths :: PathKind ;
use rustc_session :: utils :: NativeLibKind ;
use rustc_session :: { filesearch , Session } ;
use rustc_span :: symbol :: Symbol ;
use rustc_target :: spec :: crt_objects :: { CrtObjects , CrtObjectsFallback } ;
use rustc_target :: spec :: { LinkOutputKind , LinkerFlavor , LldFlavor } ;
use rustc_target :: spec :: { PanicStrategy , RelocModel , RelroLevel } ;
use super :: archive :: ArchiveBuilder ;
use super :: command :: Command ;
use super :: linker :: { self , Linker } ;
use super :: rpath :: { self , RPathConfig } ;
use crate :: { looks_like_rust_object_file , CodegenResults , CrateInfo , METADATA_FILENAME } ;
use cc :: windows_registry ;
use tempfile :: Builder as TempFileBuilder ;
use std :: ffi :: OsString ;
use std :: path :: { Path , PathBuf } ;
use std :: process :: { ExitStatus , Output , Stdio } ;
use std :: { ascii , char , env , fmt , fs , io , mem , str } ;
pub fn remove ( sess : & Session , path : & Path ) {
if let Err ( e ) = fs :: remove_file ( path ) {
sess . err ( & format ! ( "failed to remove {}: {}" , path . display ( ) , e ) ) ;
}
}
pub fn link_binary < 'a , B : ArchiveBuilder < 'a > > (
sess : & 'a Session ,
codegen_results : & CodegenResults ,
outputs : & OutputFilenames ,
crate_name : & str ,
target_cpu : & str ,
) {
let _timer = sess . timer ( "link_binary" ) ;
let output_metadata = sess . opts . output_types . contains_key ( & OutputType :: Metadata ) ;
for & crate_type in sess . crate_types ( ) . iter ( ) {
if ( sess . opts . debugging_opts . no_codegen || ! sess . opts . output_types . should_codegen ( ) )
&& ! output_metadata
&& crate_type == CrateType :: Executable
{
continue ;
}
if invalid_output_for_target ( sess , crate_type ) {
bug ! (
"invalid output type `{:?}` for target os `{}`" ,
crate_type ,
sess . opts . target_triple
) ;
}
sess . time ( "link_binary_check_files_are_writeable" , || {
for obj in codegen_results . modules . iter ( ) . filter_map ( | m | m . object . as_ref ( ) ) {
check_file_is_writeable ( obj , sess ) ;
}
} ) ;
if outputs . outputs . should_codegen ( ) {
let tmpdir = TempFileBuilder :: new ( )
. prefix ( "rustc" )
. tempdir ( )
. unwrap_or_else ( | err | sess . fatal ( & format ! ( "couldn't create a temp dir: {}" , err ) ) ) ;
let path = MaybeTempDir :: new ( tmpdir , sess . opts . cg . save_temps ) ;
let out_filename = out_filename ( sess , crate_type , outputs , crate_name ) ;
match crate_type {
CrateType :: Rlib => {
let _timer = sess . timer ( "link_rlib" ) ;
link_rlib :: < B > ( sess , codegen_results , RlibFlavor :: Normal , & out_filename , & path )
. build ( ) ;
}
CrateType :: Staticlib => {
link_staticlib :: < B > ( sess , codegen_results , & out_filename , & path ) ;
}
_ => {
link_natively :: < B > (
sess ,
crate_type ,
& out_filename ,
codegen_results ,
path . as_ref ( ) ,
target_cpu ,
) ;
}
}
if sess . opts . json_artifact_notifications {
sess . parse_sess . span_diagnostic . emit_artifact_notification ( & out_filename , "link" ) ;
}
}
}
sess . time ( "link_binary_remove_temps" , || {
if ! sess . opts . cg . save_temps {
if sess . opts . output_types . should_codegen ( )
&& ! preserve_objects_for_their_debuginfo ( sess )
{
for obj in codegen_results . modules . iter ( ) . filter_map ( | m | m . object . as_ref ( ) ) {
remove ( sess , obj ) ;
}
}
if let Some ( ref metadata_module ) = codegen_results . metadata_module {
if let Some ( ref obj ) = metadata_module . object {
remove ( sess , obj ) ;
}
}
if let Some ( ref allocator_module ) = codegen_results . allocator_module {
if let Some ( ref obj ) = allocator_module . object {
remove ( sess , obj ) ;
}
}
}
} ) ;
}
fn get_linker (
sess : & Session ,
linker : & Path ,
flavor : LinkerFlavor ,
self_contained : bool ,
) -> Command {
let msvc_tool = windows_registry :: find_tool ( & sess . opts . target_triple . triple ( ) , "link.exe" ) ;
let mut cmd = match linker . to_str ( ) {
Some ( linker ) if cfg ! ( windows ) && linker . ends_with ( ".bat" ) => Command :: bat_script ( linker ) ,
_ => match flavor {
LinkerFlavor :: Lld ( f ) => Command :: lld ( linker , f ) ,
LinkerFlavor :: Msvc
if sess . opts . cg . linker . is_none ( ) && sess . target . target . options . linker . is_none ( ) =>
{
Command :: new ( msvc_tool . as_ref ( ) . map ( | t | t . path ( ) ) . unwrap_or ( linker ) )
}
_ => Command :: new ( linker ) ,
} ,
} ;
let t = & sess . target . target ;
if ( flavor == LinkerFlavor :: Msvc || flavor == LinkerFlavor :: Lld ( LldFlavor :: Link ) )
&& t . target_vendor == "uwp"
{
if let Some ( ref tool ) = msvc_tool {
let original_path = tool . path ( ) ;
if let Some ( ref root_lib_path ) = original_path . ancestors ( ) . nth ( 4 ) {
let arch = match t . arch . as_str ( ) {
"x86_64" => Some ( "x64" . to_string ( ) ) ,
"x86" => Some ( "x86" . to_string ( ) ) ,
"aarch64" => Some ( "arm64" . to_string ( ) ) ,
"arm" => Some ( "arm" . to_string ( ) ) ,
_ => None ,
} ;
if let Some ( ref a ) = arch {
let mut arg = OsString :: from ( "/LIBPATH:" ) ;
arg . push ( format ! ( "{}\\lib\\{}\\store" , root_lib_path . display ( ) , a . to_string ( ) ) ) ;
cmd . arg ( & arg ) ;
} else {
warn ! ( "arch is not supported" ) ;
}
} else {
warn ! ( "MSVC root path lib location not found" ) ;
}
} else {
warn ! ( "link.exe not found" ) ;
}
}
let mut new_path = sess . host_filesearch ( PathKind :: All ) . get_tools_search_paths ( self_contained ) ;
let mut msvc_changed_path = false ;
if sess . target . target . options . is_like_msvc {
if let Some ( ref tool ) = msvc_tool {
cmd . args ( tool . args ( ) ) ;
for & ( ref k , ref v ) in tool . env ( ) {
if k == "PATH" {
new_path . extend ( env :: split_paths ( v ) ) ;
msvc_changed_path = true ;
} else {
cmd . env ( k , v ) ;
}
}
}
}
if ! msvc_changed_path {
if let Some ( path ) = env :: var_os ( "PATH" ) {
new_path . extend ( env :: split_paths ( & path ) ) ;
}
}
cmd . env ( "PATH" , env :: join_paths ( new_path ) . unwrap ( ) ) ;
cmd
}
pub fn each_linked_rlib (
info : & CrateInfo ,
f : & mut dyn FnMut ( CrateNum , & Path ) ,
) -> Result < ( ) , String > {
let crates = info . used_crates_static . iter ( ) ;
let mut fmts = None ;
for ( ty , list ) in info . dependency_formats . iter ( ) {
match ty {
CrateType :: Executable
| CrateType :: Staticlib
| CrateType :: Cdylib
| CrateType :: ProcMacro => {
fmts = Some ( list ) ;
break ;
}
_ => { }
}
}
let fmts = match fmts {
Some ( f ) => f ,
None => return Err ( "could not find formats for rlibs" . to_string ( ) ) ,
} ;
for & ( cnum , ref path ) in crates {
match fmts . get ( cnum . as_usize ( ) - 1 ) {
Some ( & Linkage :: NotLinked | & Linkage :: IncludedFromDylib ) => continue ,
Some ( _ ) => { }
None => return Err ( "could not find formats for rlibs" . to_string ( ) ) ,
}
let name = & info . crate_name [ & cnum ] ;
let path = match * path {
LibSource :: Some ( ref p ) => p ,
LibSource :: MetadataOnly => {
return Err ( format ! (
"could not find rlib for: `{}`, found rmeta (metadata) file" ,
name
) ) ;
}
LibSource :: None => return Err ( format ! ( "could not find rlib for: `{}`" , name ) ) ,
} ;
f ( cnum , & path ) ;
}
Ok ( ( ) )
}
pub fn emit_metadata ( sess : & Session , metadata : & EncodedMetadata , tmpdir : & MaybeTempDir ) -> PathBuf {
let out_filename = tmpdir . as_ref ( ) . join ( METADATA_FILENAME ) ;
let result = fs :: write ( & out_filename , & metadata . raw_data ) ;
if let Err ( e ) = result {
sess . fatal ( & format ! ( "failed to write {}: {}" , out_filename . display ( ) , e ) ) ;
}
out_filename
}
fn link_rlib < 'a , B : ArchiveBuilder < 'a > > (
sess : & 'a Session ,
codegen_results : & CodegenResults ,
flavor : RlibFlavor ,
out_filename : & Path ,
tmpdir : & MaybeTempDir ,
) -> B {
info ! ( "preparing rlib to {:?}" , out_filename ) ;
let mut ab = < B as ArchiveBuilder > :: new ( sess , out_filename , None ) ;
for obj in codegen_results . modules . iter ( ) . filter_map ( | m | m . object . as_ref ( ) ) {
ab . add_file ( obj ) ;
}
for lib in codegen_results . crate_info . used_libraries . iter ( ) {
match lib . kind {
NativeLibKind :: StaticBundle => { }
NativeLibKind :: StaticNoBundle
| NativeLibKind :: Dylib
| NativeLibKind :: Framework
| NativeLibKind :: RawDylib
| NativeLibKind :: Unspecified => continue ,
}
if let Some ( name ) = lib . name {
ab . add_native_library ( name ) ;
}
}
ab . update_symbols ( ) ;
match flavor {
RlibFlavor :: Normal => {
ab . add_file ( & emit_metadata ( sess , & codegen_results . metadata , tmpdir ) ) ;
if ! sess . target . target . options . is_like_osx {
ab . update_symbols ( ) ;
}
}
RlibFlavor :: StaticlibBase => {
let obj = codegen_results . allocator_module . as_ref ( ) . and_then ( | m | m . object . as_ref ( ) ) ;
if let Some ( obj ) = obj {
ab . add_file ( obj ) ;
}
}
}
ab
}
fn link_staticlib < 'a , B : ArchiveBuilder < 'a > > (
sess : & 'a Session ,
codegen_results : & CodegenResults ,
out_filename : & Path ,
tempdir : & MaybeTempDir ,
) {
let mut ab =
link_rlib :: < B > ( sess , codegen_results , RlibFlavor :: StaticlibBase , out_filename , tempdir ) ;
let mut all_native_libs = vec ! [ ] ;
let res = each_linked_rlib ( & codegen_results . crate_info , & mut | cnum , path | {
let name = & codegen_results . crate_info . crate_name [ & cnum ] ;
let native_libs = & codegen_results . crate_info . native_libraries [ & cnum ] ;
let skip_object_files = native_libs
. iter ( )
. any ( | lib | lib . kind == NativeLibKind :: StaticBundle && ! relevant_lib ( sess , lib ) ) ;
ab . add_rlib (
path ,
& name . as_str ( ) ,
are_upstream_rust_objects_already_included ( sess )
&& ! ignored_for_lto ( sess , & codegen_results . crate_info , cnum ) ,
skip_object_files ,
)
. unwrap ( ) ;
all_native_libs . extend ( codegen_results . crate_info . native_libraries [ & cnum ] . iter ( ) . cloned ( ) ) ;
} ) ;
if let Err ( e ) = res {
sess . fatal ( & e ) ;
}
ab . update_symbols ( ) ;
ab . build ( ) ;
if ! all_native_libs . is_empty ( ) {
if sess . opts . prints . contains ( & PrintRequest :: NativeStaticLibs ) {
print_native_static_libs ( sess , & all_native_libs ) ;
}
}
}
fn link_natively < 'a , B : ArchiveBuilder < 'a > > (
sess : & 'a Session ,
crate_type : CrateType ,
out_filename : & Path ,
codegen_results : & CodegenResults ,
tmpdir : & Path ,
target_cpu : & str ,
) {
info ! ( "preparing {:?} to {:?}" , crate_type , out_filename ) ;
let ( linker_path , flavor ) = linker_and_flavor ( sess ) ;
let mut cmd = linker_with_args :: < B > (
& linker_path ,
flavor ,
sess ,
crate_type ,
tmpdir ,
out_filename ,
codegen_results ,
target_cpu ,
) ;
linker :: disable_localization ( & mut cmd ) ;
for & ( ref k , ref v ) in & sess . target . target . options . link_env {
cmd . env ( k , v ) ;
}
for k in & sess . target . target . options . link_env_remove {
cmd . env_remove ( k ) ;
}
if sess . opts . debugging_opts . print_link_args {
println ! ( "{:?}" , & cmd ) ;
}
sess . abort_if_errors ( ) ;
info ! ( "{:?}" , & cmd ) ;
let retry_on_segfault = env :: var ( "RUSTC_RETRY_LINKER_ON_SEGFAULT" ) . is_ok ( ) ;
let mut prog ;
let mut i = 0 ;
loop {
i += 1 ;
prog = sess . time ( "run_linker" , || exec_linker ( sess , & cmd , out_filename , tmpdir ) ) ;
let output = match prog {
Ok ( ref output ) => output ,
Err ( _ ) => break ,
} ;
if output . status . success ( ) {
break ;
}
let mut out = output . stderr . clone ( ) ;
out . extend ( & output . stdout ) ;
let out = String :: from_utf8_lossy ( & out ) ;
if sess . target . target . options . linker_is_gnu
&& flavor != LinkerFlavor :: Ld
&& ( out . contains ( "unrecognized command line option" )
|| out . contains ( "unknown argument" ) )
&& out . contains ( "-no-pie" )
&& cmd . get_args ( ) . iter ( ) . any ( | e | e . to_string_lossy ( ) == "-no-pie" )
{
info ! ( "linker output: {:?}" , out ) ;
warn ! ( "Linker does not support -no-pie command line option. Retrying without." ) ;
for arg in cmd . take_args ( ) {
if arg . to_string_lossy ( ) != "-no-pie" {
cmd . arg ( arg ) ;
}
}
info ! ( "{:?}" , & cmd ) ;
continue ;
}
if sess . target . target . options . linker_is_gnu
&& flavor != LinkerFlavor :: Ld
&& ( out . contains ( "unrecognized command line option" )
|| out . contains ( "unknown argument" ) )
&& ( out . contains ( "-static-pie" ) || out . contains ( "--no-dynamic-linker" ) )
&& cmd . get_args ( ) . iter ( ) . any ( | e | e . to_string_lossy ( ) == "-static-pie" )
{
info ! ( "linker output: {:?}" , out ) ;
warn ! (
"Linker does not support -static-pie command line option. Retrying with -static instead."
) ;
let self_contained = crt_objects_fallback ( sess , crate_type ) ;
let opts = & sess . target . target . options ;
let pre_objects = if self_contained {
& opts . pre_link_objects_fallback
} else {
& opts . pre_link_objects
} ;
let post_objects = if self_contained {
& opts . post_link_objects_fallback
} else {
& opts . post_link_objects
} ;
let get_objects = | objects : & CrtObjects , kind | {
objects
. get ( & kind )
. iter ( )
. copied ( )
. flatten ( )
. map ( | obj | get_object_file_path ( sess , obj , self_contained ) . into_os_string ( ) )
. collect :: < Vec < _ > > ( )
} ;
let pre_objects_static_pie = get_objects ( pre_objects , LinkOutputKind :: StaticPicExe ) ;
let post_objects_static_pie = get_objects ( post_objects , LinkOutputKind :: StaticPicExe ) ;
let mut pre_objects_static = get_objects ( pre_objects , LinkOutputKind :: StaticNoPicExe ) ;
let mut post_objects_static = get_objects ( post_objects , LinkOutputKind :: StaticNoPicExe ) ;
assert ! ( pre_objects_static . is_empty ( ) || ! pre_objects_static_pie . is_empty ( ) ) ;
assert ! ( post_objects_static . is_empty ( ) || ! post_objects_static_pie . is_empty ( ) ) ;
for arg in cmd . take_args ( ) {
if arg . to_string_lossy ( ) == "-static-pie" {
cmd . arg ( "-static" ) ;
} else if pre_objects_static_pie . contains ( & arg ) {
cmd . args ( mem :: take ( & mut pre_objects_static ) ) ;
} else if post_objects_static_pie . contains ( & arg ) {
cmd . args ( mem :: take ( & mut post_objects_static ) ) ;
} else {
cmd . arg ( arg ) ;
}
}
info ! ( "{:?}" , & cmd ) ;
continue ;
}
if ! retry_on_segfault || i > 3 {
break ;
}
let msg_segv = "clang: error: unable to execute command: Segmentation fault: 11" ; super :: vxworks_base :: opts ( ) ;
if out . contains ( msg_segv ) || out . contains ( msg_bus ) {
warn ! (
"looks like the linker segfaulted when we tried to call it, \
                 automatically retrying again. cmd = {:?}, out = {}."
,
cmd , out ,
) ;
continue ;
}
if is_illegal_instruction ( & output . status ) {
warn ! (
"looks like the linker hit an illegal instruction when we \
                 tried to call it, automatically retrying again. cmd = {:?}, ]\
                 out = {}, status = {}."
,
cmd , out , output . status ,
) ;
continue ;
}
# [ cfg ( unix ) ]
fn is_illegal_instruction ( status : & ExitStatus ) -> bool {
use std :: os :: unix :: prelude :: * ;
status . signal ( ) == Some ( libc :: SIGILL )
}
# [ cfg ( windows ) ]
fn is_illegal_instruction ( _status : & ExitStatus ) -> bool {
false
}
}
match prog {
Ok ( prog ) => {
fn escape_string ( s : & [ u8 ] ) -> String {
str :: from_utf8 ( s ) . map ( | s | s . to_owned ( ) ) . unwrap_or_else ( |_| {
let mut x = "Non-UTF-8 output: " . to_string ( ) ;
x . extend ( s . iter ( ) . flat_map ( | & b | ascii :: escape_default ( b ) ) . map ( char :: from ) ) ;
x
} )
}
if ! prog . status . success ( ) {
let mut output = prog . stderr . clone ( ) ;
output . extend_from_slice ( & prog . stdout ) ;
sess . struct_err ( & format ! (
"linking with `{}` failed: {}" ,
linker_path . display ( ) ,
prog . status
) )
. note ( & format ! ( "{:?}" , & cmd ) )
. note ( & escape_string ( & output ) )
. emit ( ) ;
if let Some ( code ) = prog . status . code ( ) {
if sess . target . target . options . is_like_msvc
&& flavor == LinkerFlavor :: Msvc
&& sess . opts . cg . linker . is_none ( )
&& linker_path . to_str ( ) == Some ( "link.exe" )
&& ( code < 1000 || code > 9999 )
{
let is_vs_installed = windows_registry :: find_vs_version ( ) . is_ok ( ) ;
let has_linker = windows_registry :: find_tool (
& sess . opts . target_triple . triple ( ) ,
"link.exe" ,
)
. is_some ( ) ;
sess . note_without_error ( "`link.exe` returned an unexpected error" ) ;
if is_vs_installed && has_linker {
sess . note_without_error (
"the Visual Studio build tools may need to be repaired \
                                using the Visual Studio installer"
,
) ;
sess . note_without_error (
"or a necessary component may be missing from the \
                                \"C++ build tools\" workload"
,
) ;
} else if is_vs_installed {
sess . note_without_error (
"in the Visual Studio installer, ensure the \
                                \"C++ build tools\" workload is selected"
,
) ;
} else {
sess . note_without_error (
"you may need to install Visual Studio build tools with the \
                                \"C++ build tools\" workload"
,
) ;
}
}
}
sess . abort_if_errors ( ) ;
}
info ! ( "linker stderr:\n{}" , escape_string ( & prog . stderr ) ) ;
info ! ( "linker stdout:\n{}" , escape_string ( & prog . stdout ) ) ;
}
Err ( e ) => {
let linker_not_found = e . kind ( ) == io :: ErrorKind :: NotFound ;
let mut linker_error = {
if linker_not_found {
sess . struct_err ( & format ! ( "linker `{}` not found" , linker_path . display ( ) ) )
} else {
sess . struct_err ( & format ! (
"could not exec the linker `{}`" ,
linker_path . display ( )
) )
}
} ;
linker_error . note ( & e . to_string ( ) ) ;
if ! linker_not_found {
linker_error . note ( & format ! ( "{:?}" , & cmd ) ) ;
}
linker_error . emit ( ) ;
if sess . target . target . options . is_like_msvc && linker_not_found {
sess . note_without_error (
"the msvc targets depend on the msvc linker \
                     but `link.exe` was not found"
,
) ;
sess . note_without_error (
"please ensure that VS 2013, VS 2015, VS 2017 or VS 2019 \
                     was installed with the Visual C++ option"
,
) ;
}
sess . abort_if_errors ( ) ;
}
}
if sess . target . target . options . is_like_osx
&& sess . opts . debuginfo != DebugInfo :: None
&& ! preserve_objects_for_their_debuginfo ( sess )
{
if let Err ( e ) = Command :: new ( "dsymutil" ) . arg ( out_filename ) . output ( ) {
sess . fatal ( & format ! ( "failed to run dsymutil: {}" , e ) )
}
}
}
fn link_sanitizers ( sess : & Session , crate_type : CrateType , linker : & mut dyn Linker ) {
let needs_runtime = match crate_type {
CrateType :: Executable => true ,
CrateType :: Dylib | CrateType :: Cdylib | CrateType :: ProcMacro => {
sess . target . target . options . is_like_osx
}
CrateType :: Rlib | CrateType :: Staticlib => false ,
} ;
if ! needs_runtime {
return ;
}
let sanitizer = sess . opts . debugging_opts . sanitizer ;
if sanitizer . contains ( SanitizerSet :: ADDRESS ) {
link_sanitizer_runtime ( sess , linker , "asan" ) ;
}
if sanitizer . contains ( SanitizerSet :: LEAK ) {
link_sanitizer_runtime ( sess , linker , "lsan" ) ;
}
if sanitizer . contains ( SanitizerSet :: MEMORY ) {
link_sanitizer_runtime ( sess , linker , "msan" ) ;
}
if sanitizer . contains ( SanitizerSet :: THREAD ) {
link_sanitizer_runtime ( sess , linker , "tsan" ) ;
}
}
fn link_sanitizer_runtime ( sess : & Session , linker : & mut dyn Linker , name : & str ) {
let default_sysroot = filesearch :: get_or_default_sysroot ( ) ;
let default_tlib =
filesearch :: make_target_lib_path ( & default_sysroot , sess . opts . target_triple . triple ( ) ) ;
let channel = option_env ! ( "CFG_RELEASE_CHANNEL" )
. map ( | channel | format ! ( "-{}" , channel ) )
. unwrap_or_default ( ) ;
match sess . opts . target_triple . triple ( ) {
"x86_64-apple-darwin" => {
let libname = format ! ( "rustc{}_rt.{}" , channel , name ) ;
let rpath = default_tlib . to_str ( ) . expect ( "non-utf8 component in path" ) ;
linker . args ( & [ "-Wl,-rpath" , "-Xlinker" , rpath ] ) ;
linker . link_dylib ( Symbol :: intern ( & libname ) ) ;
}
"aarch64-fuchsia"
| "aarch64-unknown-linux-gnu"
| "x86_64-fuchsia"
| "x86_64-unknown-freebsd"
| "x86_64-unknown-linux-gnu" => {
let filename = format ! ( "librustc{}_rt.{}.a" , channel , name ) ;
let path = default_tlib . join ( & filename ) ;
linker . link_whole_rlib ( & path ) ;
}
_ => { }
}
}
pub fn ignored_for_lto ( sess : & Session , info : & CrateInfo , cnum : CrateNum ) -> bool {
! sess . target . target . options . no_builtins
&& ( info . compiler_builtins == Some ( cnum ) || info . is_no_builtins . contains ( & cnum ) )
}
fn linker_and_flavor ( sess : & Session ) -> ( PathBuf , LinkerFlavor ) {
fn infer_from (
sess : & Session ,
linker : Option < PathBuf > ,
flavor : Option < LinkerFlavor > ,
) -> Option < ( PathBuf , LinkerFlavor ) > {
match ( linker , flavor ) {
( Some ( linker ) , Some ( flavor ) ) => Some ( ( linker , flavor ) ) ,
( None , Some ( flavor ) ) => Some ( (
PathBuf :: from ( match flavor {
LinkerFlavor :: Em => {
if cfg ! ( windows ) {
"emcc.bat"
} else {
"emcc"
}
}
LinkerFlavor :: Gcc => {
if cfg ! ( any ( target_os = "solaris" , target_os = "illumos" ) ) {
"gcc"
} else {
"cc"
}
}
LinkerFlavor :: Ld => "ld" ,
LinkerFlavor :: Msvc => "link.exe" ,
LinkerFlavor :: Lld ( _ ) => "lld" ,
LinkerFlavor :: PtxLinker => "rust-ptx-linker" ,
} ) ,
flavor ,
) ) ,
( Some ( linker ) , None ) => {
let stem = linker . file_stem ( ) . and_then ( | stem | stem . to_str ( ) ) . unwrap_or_else ( || {
sess . fatal ( "couldn't extract file stem from specified linker" )
} ) ;
let flavor = if stem == "emcc" {
LinkerFlavor :: Em
} else if stem == "gcc"
|| stem . ends_with ( "-gcc" )
|| stem == "clang"
|| stem . ends_with ( "-clang" )
{
LinkerFlavor :: Gcc
} else if stem == "ld" || stem == "ld.lld" || stem . ends_with ( "-ld" ) {
LinkerFlavor :: Ld
} else if stem == "link" || stem == "lld-link" {
LinkerFlavor :: Msvc
} else if stem == "lld" || stem == "rust-lld" {
LinkerFlavor :: Lld ( sess . target . target . options . lld_flavor )
} else {
sess . target . target . linker_flavor
} ;
Some ( ( linker , flavor ) )
}
( None , None ) => None ,
}
}
if let Some ( ret ) = infer_from ( sess , sess . opts . cg . linker . clone ( ) , sess . opts . cg . linker_flavor ) {
return ret ;
}
if let Some ( ret ) = infer_from (
sess ,
sess . target . target . options . linker . clone ( ) . map ( PathBuf :: from ) ,
Some ( sess . target . target . linker_flavor ) ,
) {
return ret ;
}
bug ! ( "Not enough information provided to determine how to invoke the linker" ) ;
}
fn preserve_objects_for_their_debuginfo ( sess : & Session ) -> bool {
if sess . opts . debuginfo == config :: DebugInfo :: None {
return false ;
}
let output_linked =
sess . crate_types ( ) . iter ( ) . any ( | & x | x != CrateType :: Rlib && x != CrateType :: Staticlib ) ;
if ! output_linked {
return false ;
}
if sess . target . target . options . is_like_osx {
return ! sess . opts . debugging_opts . run_dsymutil ;
}
false
}
pub fn archive_search_paths ( sess : & Session ) -> Vec < PathBuf > {
sess . target_filesearch ( PathKind :: Native ) . search_path_dirs ( )
}
enum RlibFlavor {
Normal ,
StaticlibBase ,
}
fn print_native_static_libs ( sess : & Session , all_native_libs : & [ NativeLib ] ) {
let lib_args : Vec < _ > = all_native_libs
. iter ( )
. filter ( | l | relevant_lib ( sess , l ) )
. filter_map ( | lib | {
let name = lib . name ? ;
match lib . kind {
NativeLibKind :: StaticNoBundle
| NativeLibKind :: Dylib
| NativeLibKind :: Unspecified => {
if sess . target . target . options . is_like_msvc {
Some ( format ! ( "{}.lib" , name ) )
} else {
Some ( format ! ( "-l{}" , name ) )
}
}
NativeLibKind :: Framework => {
Some ( format ! ( "-framework {}" , name ) )
}
NativeLibKind :: StaticBundle | NativeLibKind :: RawDylib => None ,
}
} )
. collect ( ) ;
if ! lib_args . is_empty ( ) {
sess . note_without_error (
"Link against the following native artifacts when linking \
                                 against this static library. The order and any duplication \
                                 can be significant on some platforms."
,
) ;
sess . note_without_error ( & format ! ( "native-static-libs: {}" , & lib_args . join ( " " ) ) ) ;
}
}
fn get_object_file_path ( sess : & Session , name : & str , self_contained : bool ) -> PathBuf {
let fs = sess . target_filesearch ( PathKind :: Native ) ;
let file_path = fs . get_lib_path ( ) . join ( name ) ;
if file_path . exists ( ) {
return file_path ;
}
if self_contained {
let file_path = fs . get_self_contained_lib_path ( ) . join ( name ) ;
if file_path . exists ( ) {
return file_path ;
}
}
for search_path in fs . search_paths ( ) {
let file_path = search_path . dir . join ( name ) ;
if file_path . exists ( ) {
return file_path ;
}
}
PathBuf :: from ( name )
}
fn exec_linker (
sess : & Session ,
cmd : & Command ,
out_filename : & Path ,
tmpdir : & Path ,
) -> io :: Result < Output > {
if ! cmd . very_likely_to_exceed_some_spawn_limit ( ) {
match cmd . command ( ) . stdout ( Stdio :: piped ( ) ) . stderr ( Stdio :: piped ( ) ) . spawn ( ) {
Ok ( child ) => {
let output = child . wait_with_output ( ) ;
flush_linked_file ( & output , out_filename ) ? ;
return output ;
}
Err ( ref e ) if command_line_too_big ( e ) => {
info ! ( "command line to linker was too big: {}" , e ) ;
}
Err ( e ) => return Err ( e ) ,
}
}
info ! ( "falling back to passing arguments to linker via an @-file" ) ;
let mut cmd2 = cmd . clone ( ) ;
let mut args = String :: new ( ) ;
for arg in cmd2 . take_args ( ) {
args . push_str (
& Escape {
arg : arg . to_str ( ) . unwrap ( ) ,
is_like_msvc : sess . target . target . options . is_like_msvc ,
}
. to_string ( ) ,
) ;
args . push ( '\n' ) ;
}
let file = tmpdir . join ( "linker-arguments" ) ;
let bytes = if sess . target . target . options . is_like_msvc {
let mut out = Vec :: with_capacity ( ( 1 + args . len ( ) ) * 2 ) ;
for c in std :: iter :: once ( 0xFEFF ) . chain ( args . encode_utf16 ( ) ) {
out . push ( c as u8 ) ;
out . push ( ( c > > 8 ) as u8 ) ;
}
out
} else {
args . into_bytes ( )
} ;
fs :: write ( & file , & bytes ) ? ;
cmd2 . arg ( format ! ( "@{}" , file . display ( ) ) ) ;
info ! ( "invoking linker {:?}" , cmd2 ) ;
let output = cmd2 . output ( ) ;
flush_linked_file ( & output , out_filename ) ? ;
return output ;
# [ cfg ( unix ) ]
fn flush_linked_file ( _ : & io :: Result < Output > , _ : & Path ) -> io :: Result < ( ) > {
Ok ( ( ) )
}
# [ cfg ( windows ) ]
fn flush_linked_file (
command_output : & io :: Result < Output > ,
out_filename : & Path ,
) -> io :: Result < ( ) > {
if let & Ok ( ref out ) = command_output {
if out . status . success ( ) {
if let Ok ( of ) = fs :: OpenOptions :: new ( ) . write ( true ) . open ( out_filename ) {
of . sync_all ( ) ? ;
}
}
}
Ok ( ( ) )
}
# [ cfg ( unix ) ]
fn command_line_too_big ( err : & io :: Error ) -> bool {
err . raw_os_error ( ) == Some ( :: libc :: E2BIG )
}
# [ cfg ( windows ) ]
fn command_line_too_big ( err : & io :: Error ) -> bool {
const ERROR_FILENAME_EXCED_RANGE : i32 = 206 ;
err . raw_os_error ( ) == Some ( ERROR_FILENAME_EXCED_RANGE )
}
struct Escape < 'a > {
arg : & 'a str ,
is_like_msvc : bool ,
}
impl < 'a > fmt :: Display for Escape < 'a > {
fn fmt ( & self , f : & mut fmt :: Formatter < '_ > ) -> fmt :: Result {
if self . is_like_msvc {
write ! ( f , "\"" ) ? ;
for c in self . arg . chars ( ) {
match c {
'"' => write ! ( f , "\\{}" , c ) ? ,
c => write ! ( f , "{}" , c ) ? ,
}
}
write ! ( f , "\"" ) ? ;
} else {
for c in self . arg . chars ( ) {
match c {
'\\' | ' ' => write ! ( f , "\\{}" , c ) ? ,
c => write ! ( f , "{}" , c ) ? ,
}
}
}
Ok ( ( ) )
}
}
}
fn link_output_kind ( sess : & Session , crate_type : CrateType ) -> LinkOutputKind {
let kind = match ( crate_type , sess . crt_static ( Some ( crate_type ) ) , sess . relocation_model ( ) ) {
( CrateType :: Executable , false , RelocModel :: Pic ) => LinkOutputKind :: DynamicPicExe ,
( CrateType :: Executable , false , _ ) => LinkOutputKind :: DynamicNoPicExe ,
( CrateType :: Executable , true , RelocModel :: Pic ) => LinkOutputKind :: StaticPicExe ,
( CrateType :: Executable , true , _ ) => LinkOutputKind :: StaticNoPicExe ,
( _ , true , _ ) => LinkOutputKind :: StaticDylib ,
( _ , false , _ ) => LinkOutputKind :: DynamicDylib ,
} ;
let opts = & sess . target . target . options ;
let pic_exe_supported = opts . position_independent_executables ;
let static_pic_exe_supported = opts . static_position_independent_executables ;
let static_dylib_supported = opts . crt_static_allows_dylibs ;
match kind {
LinkOutputKind :: DynamicPicExe if ! pic_exe_supported => LinkOutputKind :: DynamicNoPicExe ,
LinkOutputKind :: StaticPicExe if ! static_pic_exe_supported => LinkOutputKind :: StaticNoPicExe ,
LinkOutputKind :: StaticDylib if ! static_dylib_supported => LinkOutputKind :: DynamicDylib ,
_ => kind ,
}
}
fn detect_self_contained_mingw ( sess : & Session ) -> bool {
let ( linker , _ ) = linker_and_flavor ( & sess ) ;
if linker == Path :: new ( "rust-lld" ) {
return true ;
}
let linker_with_extension = if cfg ! ( windows ) && linker . extension ( ) . is_none ( ) {
linker . with_extension ( "exe" )
} else {
linker
} ;
for dir in env :: split_paths ( & env :: var_os ( "PATH" ) . unwrap_or_default ( ) ) {
let full_path = dir . join ( & linker_with_extension ) ;
if full_path . is_file ( ) && ! full_path . starts_with ( & sess . sysroot ) {
return false ;
}
}
true
}
fn crt_objects_fallback ( sess : & Session , crate_type : CrateType ) -> bool {
if let Some ( self_contained ) = sess . opts . cg . link_self_contained {
return self_contained ;
}
match sess . target . target . options . crt_objects_fallback {
Some ( CrtObjectsFallback :: Musl ) => sess . crt_static ( Some ( crate_type ) ) ,
Some ( CrtObjectsFallback :: Mingw ) => {
sess . host == sess . target . target
&& sess . target . target . target_vendor != "uwp"
&& detect_self_contained_mingw ( & sess )
}
Some ( CrtObjectsFallback :: Wasm ) => true ,
None => false ,
}
}
fn add_pre_link_objects (
cmd : & mut dyn Linker ,
sess : & Session ,
link_output_kind : LinkOutputKind ,
self_contained : bool ,
) {
let opts = & sess . target . target . options ;
let objects =
if self_contained { & opts . pre_link_objects_fallback } else { & opts . pre_link_objects } ;
for obj in objects . get ( & link_output_kind ) . iter ( ) . copied ( ) . flatten ( ) {
cmd . add_object ( & get_object_file_path ( sess , obj , self_contained ) ) ;
}
}
fn add_post_link_objects (
cmd : & mut dyn Linker ,
sess : & Session ,
link_output_kind : LinkOutputKind ,
self_contained : bool ,
) {
let opts = & sess . target . target . options ;
let objects =
if self_contained { & opts . post_link_objects_fallback } else { & opts . post_link_objects } ;
for obj in objects . get ( & link_output_kind ) . iter ( ) . copied ( ) . flatten ( ) {
cmd . add_object ( & get_object_file_path ( sess , obj , self_contained ) ) ;
}
}
fn add_pre_link_args ( cmd : & mut dyn Linker , sess : & Session , flavor : LinkerFlavor ) {
if let Some ( args ) = sess . target . target . options . pre_link_args . get ( & flavor ) {
cmd . args ( args ) ;
}
cmd . args ( & sess . opts . debugging_opts . pre_link_args ) ;
}
fn add_link_script ( cmd : & mut dyn Linker , sess : & Session , tmpdir : & Path , crate_type : CrateType ) {
match ( crate_type , & sess . target . target . options . link_script ) {
( CrateType :: Cdylib | CrateType :: Executable , Some ( script ) ) => {
if ! sess . target . target . options . linker_is_gnu {
sess . fatal ( "can only use link script when linking with GNU-like linker" ) ;
}
let file_name = [ "rustc" , & sess . target . target . llvm_target , "linkfile.ld" ] . join ( "-" ) ;
let path = tmpdir . join ( file_name ) ;
if let Err ( e ) = fs :: write ( & path , script ) {
sess . fatal ( & format ! ( "failed to write link script to {}: {}" , path . display ( ) , e ) ) ;
}
cmd . arg ( "--script" ) ;
cmd . arg ( path ) ;
}
_ => { }
}
}
fn add_user_defined_link_args (
cmd : & mut dyn Linker ,
sess : & Session ,
codegen_results : & CodegenResults ,
) {
cmd . args ( & sess . opts . cg . link_args ) ;
cmd . args ( & * codegen_results . crate_info . link_args ) ;
}
fn add_late_link_args (
cmd : & mut dyn Linker ,
sess : & Session ,
flavor : LinkerFlavor ,
crate_type : CrateType ,
codegen_results : & CodegenResults ,
) {
let any_dynamic_crate = crate_type == CrateType :: Dylib
|| codegen_results . crate_info . dependency_formats . iter ( ) . any ( | ( ty , list ) | {
* ty == crate_type && list . iter ( ) . any ( | & linkage | linkage == Linkage :: Dynamic )
} ) ;
if any_dynamic_crate {
if let Some ( args ) = sess . target . target . options . late_link_args_dynamic . get ( & flavor ) {
cmd . args ( args ) ;
}
} else {
if let Some ( args ) = sess . target . target . options . late_link_args_static . get ( & flavor ) {
cmd . args ( args ) ;
}
}
if let Some ( args ) = sess . target . target . options . late_link_args . get ( & flavor ) {
cmd . args ( args ) ;
}
}
fn add_post_link_args ( cmd : & mut dyn Linker , sess : & Session , flavor : LinkerFlavor ) {
if let Some ( args ) = sess . target . target . options . post_link_args . get ( & flavor ) {
cmd . args ( args ) ;
}
}
fn add_local_crate_regular_objects ( cmd : & mut dyn Linker , codegen_results : & CodegenResults ) {
for obj in codegen_results . modules . iter ( ) . filter_map ( | m | m . object . as_ref ( ) ) {
cmd . add_object ( obj ) ;
}
}
fn add_local_crate_allocator_objects ( cmd : & mut dyn Linker , codegen_results : & CodegenResults ) {
if let Some ( obj ) = codegen_results . allocator_module . as_ref ( ) . and_then ( | m | m . object . as_ref ( ) ) {
cmd . add_object ( obj ) ;
}
}
fn add_local_crate_metadata_objects (
cmd : & mut dyn Linker ,
crate_type : CrateType ,
codegen_results : & CodegenResults ,
) {
if crate_type == CrateType :: Dylib || crate_type == CrateType :: ProcMacro {
if let Some ( obj ) = codegen_results . metadata_module . as_ref ( ) . and_then ( | m | m . object . as_ref ( ) )
{
cmd . add_object ( obj ) ;
}
}
}
fn link_local_crate_native_libs_and_dependent_crate_libs < 'a , B : ArchiveBuilder < 'a > > (
cmd : & mut dyn Linker ,
sess : & 'a Session ,
crate_type : CrateType ,
codegen_results : & CodegenResults ,
tmpdir : & Path ,
) {
if sess . opts . debugging_opts . link_native_libraries {
add_local_native_libraries ( cmd , sess , codegen_results ) ;
}
add_upstream_rust_crates :: < B > ( cmd , sess , codegen_results , crate_type , tmpdir ) ;
if sess . opts . debugging_opts . link_native_libraries {
add_upstream_native_libraries ( cmd , sess , codegen_results , crate_type ) ;
}
}
fn add_library_search_dirs ( cmd : & mut dyn Linker , sess : & Session , self_contained : bool ) {
let lib_path = sess . target_filesearch ( PathKind :: All ) . get_lib_path ( ) ;
cmd . include_path ( & fix_windows_verbatim_for_gcc ( & lib_path ) ) ;
if self_contained {
let lib_path = sess . target_filesearch ( PathKind :: All ) . get_self_contained_lib_path ( ) ;
cmd . include_path ( & fix_windows_verbatim_for_gcc ( & lib_path ) ) ;
}
}
fn add_relro_args ( cmd : & mut dyn Linker , sess : & Session ) {
match sess . opts . debugging_opts . relro_level . unwrap_or ( sess . target . target . options . relro_level ) {
RelroLevel :: Full => cmd . full_relro ( ) ,
RelroLevel :: Partial => cmd . partial_relro ( ) ,
RelroLevel :: Off => cmd . no_relro ( ) ,
RelroLevel :: None => { }
}
}
fn add_rpath_args (
cmd : & mut dyn Linker ,
sess : & Session ,
codegen_results : & CodegenResults ,
out_filename : & Path ,
) {
if sess . opts . cg . rpath {
let target_triple = sess . opts . target_triple . triple ( ) ;
let mut get_install_prefix_lib_path = || {
let install_prefix = option_env ! ( "CFG_PREFIX" ) . expect ( "CFG_PREFIX" ) ;
let tlib = filesearch :: relative_target_lib_path ( & sess . sysroot , target_triple ) ;
let mut path = PathBuf :: from ( install_prefix ) ;
path . push ( & tlib ) ;
path
} ;
let mut rpath_config = RPathConfig {
used_crates : & codegen_results . crate_info . used_crates_dynamic ,
out_filename : out_filename . to_path_buf ( ) ,
has_rpath : sess . target . target . options . has_rpath ,
is_like_osx : sess . target . target . options . is_like_osx ,
linker_is_gnu : sess . target . target . options . linker_is_gnu ,
get_install_prefix_lib_path : & mut get_install_prefix_lib_path ,
} ;
cmd . args ( & rpath :: get_rpath_flags ( & mut rpath_config ) ) ;
}
}
fn linker_with_args < 'a , B : ArchiveBuilder < 'a > > (
path : & Path ,
flavor : LinkerFlavor ,
sess : & 'a Session ,
crate_type : CrateType ,
tmpdir : & Path ,
out_filename : & Path ,
codegen_results : & CodegenResults ,
target_cpu : & str ,
) -> Command {
let crt_objects_fallback = crt_objects_fallback ( sess , crate_type ) ;
let base_cmd = get_linker ( sess , path , flavor , crt_objects_fallback ) ;
assert ! ( base_cmd . get_args ( ) . is_empty ( ) || sess . target . target . target_vendor == "uwp" ) ;
let cmd = & mut * codegen_results . linker_info . to_linker ( base_cmd , & sess , flavor , target_cpu ) ;
let link_output_kind = link_output_kind ( sess , crate_type ) ;
add_pre_link_args ( cmd , sess , flavor ) ;
add_apple_sdk ( cmd , sess , flavor ) ;
add_link_script ( cmd , sess , tmpdir , crate_type ) ;
if sess . target . target . options . is_like_fuchsia && crate_type == CrateType :: Executable {
let prefix = if sess . opts . debugging_opts . sanitizer . contains ( SanitizerSet :: ADDRESS ) {
"asan/"
} else {
""
} ;
cmd . arg ( format ! ( "--dynamic-linker={}ld.so.1" , prefix ) ) ;
}
if sess . target . target . options . eh_frame_header {
cmd . add_eh_frame_header ( ) ;
}
if crt_objects_fallback {
cmd . no_crt_objects ( ) ;
}
add_pre_link_objects ( cmd , sess , link_output_kind , crt_objects_fallback ) ;
if sess . target . target . options . is_like_emscripten {
cmd . arg ( "-s" ) ;
cmd . arg ( if sess . panic_strategy ( ) == PanicStrategy :: Abort {
"DISABLE_EXCEPTION_CATCHING=1"
} else {
"DISABLE_EXCEPTION_CATCHING=0"
} ) ;
}
link_sanitizers ( sess , crate_type , cmd ) ;
cmd . linker_plugin_lto ( ) ;
add_library_search_dirs ( cmd , sess , crt_objects_fallback ) ;
add_local_crate_regular_objects ( cmd , codegen_results ) ;
cmd . output_filename ( out_filename ) ;
if crate_type == CrateType :: Executable && sess . target . target . options . is_like_windows {
if let Some ( ref s ) = codegen_results . windows_subsystem {
cmd . subsystem ( s ) ;
}
}
cmd . export_symbols ( tmpdir , crate_type ) ;
add_local_crate_metadata_objects ( cmd , crate_type , codegen_results ) ;
add_local_crate_allocator_objects ( cmd , codegen_results ) ;
if ! sess . link_dead_code ( ) {
let keep_metadata = crate_type == CrateType :: Dylib ;
cmd . gc_sections ( keep_metadata ) ;
}
cmd . set_output_kind ( link_output_kind , out_filename ) ;
add_relro_args ( cmd , sess ) ;
cmd . optimize ( ) ;
cmd . debuginfo ( sess . opts . debugging_opts . strip ) ;
if ! sess . opts . cg . default_linker_libraries && sess . target . target . options . no_default_libraries {
cmd . no_default_libraries ( ) ;
}
link_local_crate_native_libs_and_dependent_crate_libs :: < B > (
cmd ,
sess ,
crate_type ,
codegen_results ,
tmpdir ,
) ;
if sess . opts . cg . profile_generate . enabled ( ) || sess . opts . debugging_opts . instrument_coverage {
cmd . pgo_gen ( ) ;
}
if sess . opts . cg . control_flow_guard != CFGuard :: Disabled {
cmd . control_flow_guard ( ) ;
}
add_rpath_args ( cmd , sess , codegen_results , out_filename ) ;
add_user_defined_link_args ( cmd , sess , codegen_results ) ;
cmd . finalize ( ) ;
add_late_link_args ( cmd , sess , flavor , crate_type , codegen_results ) ;
add_post_link_objects ( cmd , sess , link_output_kind , crt_objects_fallback ) ;
add_post_link_args ( cmd , sess , flavor ) ;
cmd . take_cmd ( )
}
fn add_local_native_libraries (
cmd : & mut dyn Linker ,
sess : & Session ,
codegen_results : & CodegenResults ,
) {
let filesearch = sess . target_filesearch ( PathKind :: All ) ;
for search_path in filesearch . search_paths ( ) {
match search_path . kind {
PathKind :: Framework => {
cmd . framework_path ( & search_path . dir ) ;
}
_ => {
cmd . include_path ( & fix_windows_verbatim_for_gcc ( & search_path . dir ) ) ;
}
}
}
let relevant_libs =
codegen_results . crate_info . used_libraries . iter ( ) . filter ( | l | relevant_lib ( sess , l ) ) ;
let search_path = archive_search_paths ( sess ) ;
for lib in relevant_libs {
let name = match lib . name {
Some ( l ) => l ,
None => continue ,
} ;
match lib . kind {
NativeLibKind :: Dylib | NativeLibKind :: Unspecified => cmd . link_dylib ( name ) ,
NativeLibKind :: Framework => cmd . link_framework ( name ) ,
NativeLibKind :: StaticNoBundle => cmd . link_staticlib ( name ) ,
NativeLibKind :: StaticBundle => cmd . link_whole_staticlib ( name , & search_path ) ,
NativeLibKind :: RawDylib => {
bug ! ( "raw_dylib feature not yet implemented" ) ;
}
}
}
}
fn add_upstream_rust_crates < 'a , B : ArchiveBuilder < 'a > > (
cmd : & mut dyn Linker ,
sess : & 'a Session ,
codegen_results : & CodegenResults ,
crate_type : CrateType ,
tmpdir : & Path ,
) {
let ( _ , data ) = codegen_results
. crate_info
. dependency_formats
. iter ( )
. find ( | ( ty , _ ) | * ty == crate_type )
. expect ( "failed to find crate type in dependency format list" ) ;
let deps = & codegen_results . crate_info . used_crates_dynamic ;
let mut group_end = None ;
let mut group_start = None ;
let mut available = FxHashSet :: default ( ) ;
let mut required = FxHashSet :: default ( ) ;
let info = & codegen_results . crate_info ;
for & ( cnum , _ ) in deps . iter ( ) . rev ( ) {
if let Some ( missing ) = info . missing_lang_items . get ( & cnum ) {
let missing_crates = missing . iter ( ) . map ( | i | info . lang_item_to_crate . get ( i ) . copied ( ) ) ;
required . extend ( missing_crates ) ;
}
required . insert ( Some ( cnum ) ) ;
available . insert ( Some ( cnum ) ) ;
if required . len ( ) > available . len ( ) && group_end . is_none ( ) {
group_end = Some ( cnum ) ;
}
if required . len ( ) == available . len ( ) && group_end . is_some ( ) {
group_start = Some ( cnum ) ;
break ;
}
}
if group_end . is_some ( ) && group_start . is_none ( ) {
group_end = None ;
}
let mut compiler_builtins = None ;
for & ( cnum , _ ) in deps . iter ( ) {
if group_start == Some ( cnum ) {
cmd . group_start ( ) ;
}
let src = & codegen_results . crate_info . used_crate_source [ & cnum ] ;
match data [ cnum . as_usize ( ) - 1 ] {
_ if codegen_results . crate_info . profiler_runtime == Some ( cnum ) => {
add_static_crate :: < B > ( cmd , sess , codegen_results , tmpdir , crate_type , cnum ) ;
}
_ if codegen_results . crate_info . compiler_builtins == Some ( cnum ) => {
assert ! ( compiler_builtins . is_none ( ) ) ;
compiler_builtins = Some ( cnum ) ;
}
Linkage :: NotLinked | Linkage :: IncludedFromDylib => { }
Linkage :: Static => {
add_static_crate :: < B > ( cmd , sess , codegen_results , tmpdir , crate_type , cnum ) ;
}
Linkage :: Dynamic => add_dynamic_crate ( cmd , sess , & src . dylib . as_ref ( ) . unwrap ( ) . 0 ) ,
}
if group_end == Some ( cnum ) {
cmd . group_end ( ) ;
}
}
if let Some ( cnum ) = compiler_builtins {
add_static_crate :: < B > ( cmd , sess , codegen_results , tmpdir , crate_type , cnum ) ;
}
fn unlib < 'a > ( config : & config :: Config , stem : & 'a str ) -> & 'a str {
if stem . starts_with ( "lib" ) && ! config . target . options . is_like_windows {
& stem [ 3 .. ]
} else {
stem
}
}
fn add_static_crate < 'a , B : ArchiveBuilder < 'a > > (
cmd : & mut dyn Linker ,
sess : & 'a Session ,
codegen_results : & CodegenResults ,
tmpdir : & Path ,
crate_type : CrateType ,
cnum : CrateNum ,
) {
let src = & codegen_results . crate_info . used_crate_source [ & cnum ] ;
let cratepath = & src . rlib . as_ref ( ) . unwrap ( ) . 0 ;
let native_libs = & codegen_results . crate_info . native_libraries [ & cnum ] ;
let skip_native = native_libs
. iter ( )
. any ( | lib | lib . kind == NativeLibKind :: StaticBundle && ! relevant_lib ( sess , lib ) ) ;
if ( ! are_upstream_rust_objects_already_included ( sess )
|| ignored_for_lto ( sess , & codegen_results . crate_info , cnum ) )
&& crate_type != CrateType :: Dylib
&& ! skip_native
{
cmd . link_rlib ( & fix_windows_verbatim_for_gcc ( cratepath ) ) ;
return ;
}
let dst = tmpdir . join ( cratepath . file_name ( ) . unwrap ( ) ) ;
let name = cratepath . file_name ( ) . unwrap ( ) . to_str ( ) . unwrap ( ) ;
let name = & name [ 3 .. name . len ( ) - 5 ] ;
sess . prof . generic_activity_with_arg ( "link_altering_rlib" , name ) . run ( || {
let mut archive = < B as ArchiveBuilder > :: new ( sess , & dst , Some ( cratepath ) ) ;
archive . update_symbols ( ) ;
let mut any_objects = false ;
for f in archive . src_files ( ) {
if f == METADATA_FILENAME {
archive . remove_file ( & f ) ;
continue ;
}
let canonical = f . replace ( "-" , "_" ) ;
let canonical_name = name . replace ( "-" , "_" ) ;
let is_rust_object =
canonical . starts_with ( & canonical_name ) && looks_like_rust_object_file ( & f ) ;
let skip_because_cfg_say_so = skip_native && ! is_rust_object ;
let skip_because_lto = are_upstream_rust_objects_already_included ( sess )
&& is_rust_object
&& ( sess . target . target . options . no_builtins
|| ! codegen_results . crate_info . is_no_builtins . contains ( & cnum ) ) ;
if skip_because_cfg_say_so || skip_because_lto {
archive . remove_file ( & f ) ;
} else {
any_objects = true ;
}
}
if ! any_objects {
return ;
}
archive . build ( ) ;
if crate_type == CrateType :: Dylib
&& codegen_results . crate_info . compiler_builtins != Some ( cnum )
{
cmd . link_whole_rlib ( & fix_windows_verbatim_for_gcc ( & dst ) ) ;
} else {
cmd . link_rlib ( & fix_windows_verbatim_for_gcc ( & dst ) ) ;
}
} ) ;
}
fn add_dynamic_crate ( cmd : & mut dyn Linker , sess : & Session , cratepath : & Path ) {
let parent = cratepath . parent ( ) ;
if let Some ( dir ) = parent {
cmd . include_path ( & fix_windows_verbatim_for_gcc ( dir ) ) ;
}
let filestem = cratepath . file_stem ( ) . unwrap ( ) . to_str ( ) . unwrap ( ) ;
cmd . link_rust_dylib (
Symbol :: intern ( & unlib ( & sess . target , filestem ) ) ,
parent . unwrap_or ( Path :: new ( "" ) ) ,
) ;
}
}
fn add_upstream_native_libraries (
cmd : & mut dyn Linker ,
sess : & Session ,
codegen_results : & CodegenResults ,
crate_type : CrateType ,
) {
let ( _ , data ) = codegen_results
. crate_info
. dependency_formats
. iter ( )
. find ( | ( ty , _ ) | * ty == crate_type )
. expect ( "failed to find crate type in dependency format list" ) ;
let crates = & codegen_results . crate_info . used_crates_static ;
for & ( cnum , _ ) in crates {
for lib in codegen_results . crate_info . native_libraries [ & cnum ] . iter ( ) {
let name = match lib . name {
Some ( l ) => l ,
None => continue ,
} ;
if ! relevant_lib ( sess , & lib ) {
continue ;
}
match lib . kind {
NativeLibKind :: Dylib | NativeLibKind :: Unspecified => cmd . link_dylib ( name ) ,
NativeLibKind :: Framework => cmd . link_framework ( name ) ,
NativeLibKind :: StaticNoBundle => {
if data [ cnum . as_usize ( ) - 1 ] == Linkage :: Static {
cmd . link_staticlib ( name )
}
}
NativeLibKind :: StaticBundle => { }
NativeLibKind :: RawDylib => {
bug ! ( "raw_dylib feature not yet implemented" ) ;
}
}
}
}
}
fn relevant_lib ( sess : & Session , lib : & NativeLib ) -> bool {
match lib . cfg {
Some ( ref cfg ) => rustc_attr :: cfg_matches ( cfg , & sess . parse_sess , None ) ,
None => true ,
}
}
fn are_upstream_rust_objects_already_included ( sess : & Session ) -> bool {
match sess . lto ( ) {
config :: Lto :: Fat => true ,
config :: Lto :: Thin => {
! sess . opts . cg . linker_plugin_lto . enabled ( )
}
config :: Lto :: No | config :: Lto :: ThinLocal => false ,
}
}
fn add_apple_sdk ( cmd : & mut dyn Linker , sess : & Session , flavor : LinkerFlavor ) {
let arch = & sess . target . target . arch ;
let os = & sess . target . target . target_os ;
let llvm_target = & sess . target . target . llvm_target ;
if sess . target . target . target_vendor != "apple"
|| ! matches ! ( os . as_str ( ) , "ios" | "tvos" )
|| flavor != LinkerFlavor :: Gcc
{
return ;
}
let sdk_name = match ( arch . as_str ( ) , os . as_str ( ) ) {
( "aarch64" , "tvos" ) => "appletvos" ,
( "x86_64" , "tvos" ) => "appletvsimulator" ,
( "arm" , "ios" ) => "iphoneos" ,
( "aarch64" , "ios" ) => "iphoneos" ,
( "x86" , "ios" ) => "iphonesimulator" ,
( "x86_64" , "ios" ) if llvm_target . contains ( "macabi" ) => "macosx10.15" ,
( "x86_64" , "ios" ) => "iphonesimulator" ,
_ => {
sess . err ( & format ! ( "unsupported arch `{}` for os `{}`" , arch , os ) ) ;
return ;
}
} ;
let sdk_root = match get_apple_sdk_root ( sdk_name ) {
Ok ( s ) => s ,
Err ( e ) => {
sess . err ( & e ) ;
return ;
}
} ;
let arch_name = llvm_target . split ( '-' ) . next ( ) . expect ( "LLVM target must have a hyphen" ) ;
cmd . args ( & [ "-arch" , arch_name , "-isysroot" , & sdk_root , "-Wl,-syslibroot" , & sdk_root ] ) ;
}
fn get_apple_sdk_root ( sdk_name : & str ) -> Result < String , String > {
if let Ok ( sdkroot ) = env :: var ( "SDKROOT" ) {
let p = Path :: new ( & sdkroot ) ;
match sdk_name {
"appletvos"
if sdkroot . contains ( "TVSimulator.platform" )
|| sdkroot . contains ( "MacOSX.platform" ) => { }
"appletvsimulator"
if sdkroot . contains ( "TVOS.platform" ) || sdkroot . contains ( "MacOSX.platform" ) => { }
"iphoneos"
if sdkroot . contains ( "iPhoneSimulator.platform" )
|| sdkroot . contains ( "MacOSX.platform" ) => { }
"iphonesimulator"
if sdkroot . contains ( "iPhoneOS.platform" ) || sdkroot . contains ( "MacOSX.platform" ) => {
}
"macosx10.15"
if sdkroot . contains ( "iPhoneOS.platform" )
|| sdkroot . contains ( "iPhoneSimulator.platform" ) => { }
_ if ! p . is_absolute ( ) || p == Path :: new ( "/" ) || ! p . exists ( ) => { }
_ => return Ok ( sdkroot ) ,
}
}
let res =
Command :: new ( "xcrun" ) . arg ( "--show-sdk-path" ) . arg ( "-sdk" ) . arg ( sdk_name ) . output ( ) . and_then (
| output | {
if output . status . success ( ) {
Ok ( String :: from_utf8 ( output . stdout ) . unwrap ( ) )
} else {
let error = String :: from_utf8 ( output . stderr ) ;
let error = format ! ( "process exit with error: {}" , error . unwrap ( ) ) ;
Err ( io :: Error :: new ( io :: ErrorKind :: Other , & error [ .. ] ) )
}
} ,
) ;
match res {
Ok ( output ) => Ok ( output . trim ( ) . to_string ( ) ) ,
Err ( e ) => Err ( format ! ( "failed to get {} SDK path: {}" , sdk_name , e ) ) ,
}
}
