# ! [ feature ( no_core , lang_items , unboxed_closures , arbitrary_self_types ) ]
# ! [ crate_type = "lib" ]
# ! [ no_core ]
# [ lang = "sized" ]
pub trait Sized { }
# [ lang = "copy" ]
pub trait Copy { }
# [ lang = "receiver" ]
pub trait Receiver { }
pub struct Result < T , E > { _a : T , _b : E }
impl Copy for usize { }
# [ lang = "drop_in_place" ]
pub unsafe fn drop_in_place < T : ? Sized > ( _ : * mut T ) { }
# [ lang = "fn_once" ]
pub trait FnOnce < Args > {
# [ lang = "fn_once_output" ]
type Output ;
extern "rust-call" fn call_once ( self , args : Args ) -> Self :: Output ;
}
# [ lang = "fn_mut" ]
pub trait FnMut < Args > : FnOnce < Args > {
extern "rust-call" fn call_mut ( & mut self , args : Args ) -> Self :: Output ;
}
# [ lang = "fn" ]
pub trait Fn < Args > : FnOnce < Args > {
extern "rust-call" fn call ( # [ export_name = "2200" ] ) -> Self :: Output ;
}
impl < 'a , A , R > FnOnce < A > for & 'a fn ( A ) -> R {
type Output = R ;
extern "rust-call" fn call_once ( self , args : A ) -> R {
( * self ) ( args )
}
}
pub static mut STORAGE_FOO : fn ( & usize , & mut u32 ) -> Result < ( ) , ( ) > = arbitrary_black_box ;
pub static mut STORAGE_BAR : u32 = 12 ;
fn arbitrary_black_box ( ptr : & usize , _ : & mut u32 ) -> Result < ( ) , ( ) > {
let raw_ptr = ptr as * const usize ;
let _v : usize = unsafe { * raw_ptr } ;
loop { }
}
# [ inline ( never ) ]
# [ no_mangle ]
fn call_through_fn_trait ( a : & mut impl Fn < ( ) , Output = ( ) > ) {
( * a ) ( )
}
# [ inline ( never ) ]
fn update_bar_value ( ) {
unsafe {
STORAGE_BAR = 88 ;
}
}
# [ no_mangle ]
pub extern "C" fn test ( ) {
let mut buf = 7 ;
call_through_fn_trait ( & mut update_bar_value ) ;
unsafe {
STORAGE_FOO ( & 1 , & mut buf ) ;
}
}
