use super :: * ;
use crate :: cmp :: Ordering :: { self , Equal , Greater , Less } ;
use crate :: intrinsics ;
use crate :: mem ;
use crate :: slice :: { self , SliceIndex } ;
# [ lang = "const_ptr" ]
impl < T : ? Sized > * const T { # [ rustc_args_required_const ( 1 ) ]
# [ rustc_const_unstable ( feature = "const_ptr_is_null" , issue = "74939" ) ]
# [ inline ]
pub const fn is_null ( self ) -> bool {
( self as * const u8 ) . guaranteed_eq ( null ( ) )
}
# [ stable ( feature = "ptr_cast" , since = "1.38.0" ) ]
# [ rustc_const_stable ( feature = "const_ptr_cast" , since = "1.38.0" ) ]
# [ inline ]
pub const fn cast < U > ( self ) -> * const U {
self as _
}
# [ stable ( feature = "ptr_as_ref" , since = "1.9.0" ) ]
# [ inline ]
pub unsafe fn as_ref < 'a > ( self ) -> Option < & 'a T > {
if self . is_null ( ) { None } else { unsafe { Some ( & * self ) } }
}
# [ inline ]
# [ unstable ( feature = "ptr_as_uninit" , issue = "75402" ) ]
pub unsafe fn as_uninit_ref < 'a > ( self ) -> Option < & 'a MaybeUninit < T > >
where
T : Sized ,
{
if self . is_null ( ) { None } else { Some ( unsafe { & * ( self as * const MaybeUninit < T > ) } ) }
}
# [ stable ( feature = "rust1" , since = "1.0.0" ) ]
# [ must_use = "returns a new pointer rather than modifying its argument" ]
# [ rustc_const_unstable ( feature = "const_ptr_offset" , issue = "71499" ) ]
# [ inline ]
pub const unsafe fn offset ( self , count : isize ) -> * const T
where
T : Sized ,
{
unsafe { intrinsics :: offset ( self , count ) }
}
# [ stable ( feature = "ptr_wrapping_offset" , since = "1.16.0" ) ]
# [ must_use = "returns a new pointer rather than modifying its argument" ]
# [ rustc_const_unstable ( feature = "const_ptr_offset" , issue = "71499" ) ]
# [ inline ]
pub const fn wrapping_offset ( self , count : isize ) -> * const T
where
T : Sized ,
{
unsafe { intrinsics :: arith_offset ( self , count ) }
}
# [ stable ( feature = "ptr_offset_from" , since = "1.47.0" ) ]
# [ rustc_const_unstable ( feature = "const_ptr_offset_from" , issue = "41079" ) ]
# [ inline ]
pub const unsafe fn offset_from ( self , origin : * const T ) -> isize
where
T : Sized ,
{
let pointee_size = mem :: size_of :: < T > ( ) ;
assert ! ( 0 < pointee_size && pointee_size <= isize :: MAX as usize ) ;
unsafe { intrinsics :: ptr_offset_from ( self , origin ) }
}
# [ unstable ( feature = "const_raw_ptr_comparison" , issue = "53020" ) ]
# [ rustc_const_unstable ( feature = "const_raw_ptr_comparison" , issue = "53020" ) ]
# [ inline ]
pub const fn guaranteed_eq ( self , other : * const T ) -> bool
where
T : Sized ,
{
intrinsics :: ptr_guaranteed_eq ( self , other )
}
# [ unstable ( feature = "const_raw_ptr_comparison" , issue = "53020" ) ]
# [ rustc_const_unstable ( feature = "const_raw_ptr_comparison" , issue = "53020" ) ]
# [ inline ]
pub const fn guaranteed_ne ( self , other : * const T ) -> bool
where
T : Sized ,
{
intrinsics :: ptr_guaranteed_ne ( self , other )
}
# [ stable ( feature = "pointer_methods" , since = "1.26.0" ) ]
# [ must_use = "returns a new pointer rather than modifying its argument" ]
# [ rustc_const_unstable ( feature = "const_ptr_offset" , issue = "71499" ) ]
# [ inline ]
pub const unsafe fn add ( self , count : usize ) -> Self
where
T : Sized ,
{
unsafe { self . offset ( count as isize ) }
}
# [ stable ( feature = "pointer_methods" , since = "1.26.0" ) ]
# [ must_use = "returns a new pointer rather than modifying its argument" ]
# [ rustc_const_unstable ( feature = "const_ptr_offset" , issue = "71499" ) ]
# [ inline ]
pub const unsafe fn sub ( self , count : usize ) -> Self
where
T : Sized ,
{
unsafe { self . offset ( ( count as isize ) . wrapping_neg ( ) ) }
}
# [ stable ( feature = "pointer_methods" , since = "1.26.0" ) ]
# [ must_use = "returns a new pointer rather than modifying its argument" ]
# [ rustc_const_unstable ( feature = "const_ptr_offset" , issue = "71499" ) ]
# [ inline ]
pub const fn wrapping_add ( self , count : usize ) -> Self
where
T : Sized ,
{
self . wrapping_offset ( count as isize )
}
# [ stable ( feature = "pointer_methods" , since = "1.26.0" ) ]
# [ must_use = "returns a new pointer rather than modifying its argument" ]
# [ rustc_const_unstable ( feature = "const_ptr_offset" , issue = "71499" ) ]
# [ inline ]
pub const fn wrapping_sub ( self , count : usize ) -> Self
where
T : Sized ,
{
self . wrapping_offset ( ( count as isize ) . wrapping_neg ( ) )
}
# [ unstable ( feature = "set_ptr_value" , issue = "75091" ) ]
# [ must_use = "returns a new pointer rather than modifying its argument" ]
# [ inline ]
pub fn set_ptr_value ( mut self , val : * const u8 ) -> Self {
let thin = & mut self as * mut * const T as * mut * const u8 ;
unsafe { * thin = val } ;
self
}
# [ stable ( feature = "pointer_methods" , since = "1.26.0" ) ]
# [ inline ]
pub unsafe fn read ( self ) -> T
where
T : Sized ,
{
unsafe { read ( self ) }
}
# [ stable ( feature = "pointer_methods" , since = "1.26.0" ) ]
# [ inline ]
pub unsafe fn read_volatile ( self ) -> T
where
T : Sized ,
{
unsafe { read_volatile ( self ) }
}
# [ stable ( feature = "pointer_methods" , since = "1.26.0" ) ]
# [ inline ]
pub unsafe fn read_unaligned ( self ) -> T
where
T : Sized ,
{
unsafe { read_unaligned ( self ) }
}
# [ stable ( feature = "pointer_methods" , since = "1.26.0" ) ]
# [ inline ]
pub unsafe fn copy_to ( self , dest : * mut T , count : usize )
where
T : Sized ,
{
unsafe { copy ( self , dest , count ) }
}
# [ stable ( feature = "pointer_methods" , since = "1.26.0" ) ]
# [ inline ]
pub unsafe fn copy_to_nonoverlapping ( self , dest : * mut T , count : usize )
where
T : Sized ,
{
unsafe { copy_nonoverlapping ( self , dest , count ) }
}
# [ stable ( feature = "align_offset" , since = "1.36.0" ) ]
pub fn align_offset ( self , align : usize ) -> usize
where
T : Sized ,
{
if ! align . is_power_of_two ( ) {
panic ! ( "align_offset: align is not a power-of-two" ) ;
}
unsafe { align_offset ( self , align ) }
}
}
# [ lang = "const_slice_ptr" ]
impl < T > * const [ T ] {
# [ inline ]
# [ unstable ( feature = "slice_ptr_len" , issue = "71146" ) ]
# [ rustc_const_unstable ( feature = "const_slice_ptr_len" , issue = "71146" ) ]
pub const fn len ( self ) -> usize {
unsafe { Repr { rust : self } . raw } . len
}
# [ inline ]
# [ unstable ( feature = "slice_ptr_get" , issue = "74265" ) ]
# [ rustc_const_unstable ( feature = "slice_ptr_get" , issue = "74265" ) ]
pub const fn as_ptr ( self ) -> * const T {
self as * const T
}
# [ unstable ( feature = "slice_ptr_get" , issue = "74265" ) ]
# [ inline ]
pub unsafe fn get_unchecked < I > ( self , index : I ) -> * const I :: Output
where
I : SliceIndex < [ T ] > ,
{
unsafe { index . get_unchecked ( self ) }
}
# [ inline ]
# [ unstable ( feature = "ptr_as_uninit" , issue = "75402" ) ]
pub unsafe fn as_uninit_slice < 'a > ( self ) -> Option < & 'a [ MaybeUninit < T > ] > {
if self . is_null ( ) {
None
} else {
Some ( unsafe { slice :: from_raw_parts ( self as * const MaybeUninit < T > , self . len ( ) ) } )
}
}
}
# [ stable ( feature = "rust1" , since = "1.0.0" ) ]
impl < T : ? Sized > PartialEq for * const T {
# [ inline ]
fn eq ( & self , other : & * const T ) -> bool {
* self == * other
}
}
# [ stable ( feature = "rust1" , since = "1.0.0" ) ]
impl < T : ? Sized > Eq for * const T { }
# [ stable ( feature = "rust1" , since = "1.0.0" ) ]
impl < T : ? Sized > Ord for * const T {
# [ inline ]
fn cmp ( & self , other : & * const T ) -> Ordering {
if self < other {
Less
} else if self == other {
Equal
} else {
Greater
}
}
}
# [ stable ( feature = "rust1" , since = "1.0.0" ) ]
impl < T : ? Sized > PartialOrd for * const T {
# [ inline ]
fn partial_cmp ( & self , other : & * const T ) -> Option < Ordering > {
Some ( self . cmp ( other ) )
}
# [ inline ]
fn lt ( & self , other : & * const T ) -> bool {
* self < * other
}
# [ inline ]
fn le ( & self , other : & * const T ) -> bool {
* self <= * other
}
# [ inline ]
fn gt ( & self , other : & * const T ) -> bool {
* self > * other
}
# [ inline ]
fn ge ( & self , other : & * const T ) -> bool {
* self >= * other
}
}
