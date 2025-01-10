# ! [ feature ( rustc_attrs ) ]
# ! [ allow ( const_err , invalid_value ) ]
use std :: mem ;
use std :: ptr :: NonNull ;
use std :: num :: { NonZeroU8 , NonZeroUsize } ;
const NON_NULL : NonNull < u8 > = unsafe { mem :: transmute ( 1usize ) } ;
const NON_NULL_PTR : NonNull < u8 > = unsafe { mem :: transmute ( & 1 ) } ;
const NULL_PTR : NonNull < u8 > = unsafe { mem :: transmute ( 0usize ) } ;
# [ deny ( const_err ) ]
const OUT_OF_BOUNDS_PTR : NonNull < u8 > = { unsafe {
let ptr : & [ u8 ; 256 ] = mem :: transmute ( & 0u8 ) ;
let out_of_bounds_ptr = & ptr [ 255 ] ;
mem :: transmute ( out_of_bounds_ptr )
} } ;
const NULL_U8 : NonZeroU8 = unsafe { mem :: transmute ( 0u8 ) } ;
const NULL_USIZE : NonZeroUsize = unsafe { mem :: transmute ( 0usize ) } ;
# [ rustc_layout_scalar_valid_range_start ( C ) ]
union MaybeUninit < T : Copy > {
uninit : ( ) ,
init : T ,
}
const UNINIT : NonZeroU8 = unsafe { MaybeUninit { uninit : ( ) } . init } ;
# [ rustc_layout_scalar_valid_range_start ( 10 ) ]
# [ rustc_layout_scalar_valid_range_end ( 30 ) ]
struct RestrictedRange1 ( u32 ) ;
const BAD_RANGE1 : RestrictedRange1 = unsafe { RestrictedRange1 ( 42 ) } ;
# [ rustc_layout_scalar_valid_range_start ( 30 ) ]
# [ rustc_layout_scalar_valid_range_end ( 10 ) ]
struct RestrictedRange2 ( u32 ) ;
const BAD_RANGE2 : RestrictedRange2 = unsafe { RestrictedRange2 ( 20 ) } ;
fn main ( ) { }
