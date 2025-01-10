# ! [ allow ( unused ) ]
# ! [ allow ( const_err ) ]
use std :: mem ;
# [ repr ( C ) ]
union MaybeUninit < T : Copy > {
uninit : ( ) ,
init : T ,
}
trait Trait { }
impl Trait for bool { }
struct MyStr ( str ) ;
struct MySlice < T : ? Sized > ( bool , T ) ;
type MySliceBool = MySlice < [ bool ] > ;
const STR_VALID : & str = unsafe { mem :: transmute ( ( & 42u8 , 1usize ) ) } ;
const STR_TOO_LONG : & str = unsafe { mem :: transmute ( ( & 42u8 , 999usize ) ) } ;
const NESTED_STR_MUCH_TOO_LONG : ( & str , ) = ( unsafe { mem :: transmute ( ( & 42 , usize :: MAX ) ) } , ) ;
const STR_LENGTH_PTR : & str = unsafe { mem :: transmute ( ( & 42u8 , & 3 ) ) } ;
const MY_STR_LENGTH_PTR : & MyStr = unsafe { mem :: transmute ( ( & 42u8 , & 3 ) ) } ;
const MY_STR_MUCH_TOO_LONG : & MyStr = unsafe { mem :: transmute ( ( & 42u8 , usize :: MAX ) ) } ;
const STR_NO_INIT : & str = unsafe { mem :: transmute :: < & [ _ ] , _ > ( & [ MaybeUninit :: < u8 > { uninit : ( ) } ] ) } ;
const MYSTR_NO_INIT : & MyStr = unsafe { mem :: transmute :: < & [ _ ] , _ > ( & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ & [ MaybeUninit :: < u8 > { uninit : ( ) } ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ) } ;
const SLICE_VALID : & [ u8 ] = unsafe { mem :: transmute ( ( & 42u8 , 1usize ) ) } ;
const SLICE_LENGTH_UNINIT : & [ u8 ] = unsafe {
let uninit_len = MaybeUninit :: < usize > { uninit : ( ) } ;
mem :: transmute ( ( 42 , uninit_len ) )
} ;
const SLICE_TOO_LONG : & [ u8 ] = unsafe { mem :: transmute ( ( & 42u8 , 999usize ) ) } ;
const SLICE_LENGTH_PTR : & [ u8 ] = unsafe { mem :: transmute ( ( & 42u8 , & 3 ) ) } ;
const SLICE_TOO_LONG_BOX : Box < [ u8 ] > = unsafe { mem :: transmute ( ( & 42u8 , 999usize ) ) } ;
const SLICE_LENGTH_PTR_BOX : Box < [ u8 ] > = unsafe { mem :: transmute ( ( & 42u8 , & 3 ) ) } ;
const SLICE_CONTENT_INVALID : & [ bool ] = & [ unsafe { mem :: transmute ( 3u8 ) } ] ;
const MYSLICE_GOOD : & MySliceBool = & MySlice ( true , [ false ] ) ;
const MYSLICE_PREFIX_BAD : & MySliceBool = & MySlice ( unsafe { mem :: transmute ( 3u8 ) } , [ false ] ) ;
const MYSLICE_SUFFIX_BAD : & MySliceBool = & MySlice ( true , [ unsafe { mem :: transmute ( 3u8 ) } ] ) ;
const RAW_SLICE_VALID : * const [ u8 ] = unsafe { mem :: transmute ( ( & 42u8 , 1usize ) ) } ;
const RAW_SLICE_TOO_LONG : * const [ u8 ] = unsafe { mem :: transmute ( ( & 42u8 , 999usize ) ) } ;
const RAW_SLICE_MUCH_TOO_LONG : * const [ u8 ] = unsafe { mem :: transmute ( ( & 42u8 , usize :: MAX ) ) } ;
const RAW_SLICE_LENGTH_UNINIT : * const [ u8 ] = unsafe {
let uninit_len = MaybeUninit :: < usize > { uninit : ( ) } ;
mem :: transmute ( ( 42 , uninit_len ) )
} ;
const TRAIT_OBJ_SHORT_VTABLE_1 : & dyn Trait = unsafe { mem :: transmute ( ( & 92u8 , & 3u8 ) ) } ;
const TRAIT_OBJ_SHORT_VTABLE_2 : & dyn Trait = unsafe { mem :: transmute ( ( & 92u8 , & 3u64 ) ) } ;
const TRAIT_OBJ_INT_VTABLE : & dyn Trait = unsafe { mem :: transmute ( ( & 92u8 , 4usize ) ) } ;
const TRAIT_OBJ_UNALIGNED_VTABLE : & dyn Trait = unsafe { mem :: transmute ( ( & 92u8 , & [ 0u8 ; 128 ] ) ) } ;
const TRAIT_OBJ_BAD_DROP_FN_NULL : & dyn Trait = unsafe { mem :: transmute ( ( & 92u8 , & [ 0usize ; 8 ] ) ) } ;
const TRAIT_OBJ_BAD_DROP_FN_INT : & dyn Trait = unsafe { mem :: transmute ( ( & 92u8 , & [ 1usize ; 8 ] ) ) } ;
const TRAIT_OBJ_BAD_DROP_FN_NOT_FN_PTR : & dyn Trait = unsafe { mem :: transmute ( ( & 92u8 , & [ & 42u8 ; 8 ] ) ) } ;
const TRAIT_OBJ_CONTENT_INVALID : & dyn Trait = unsafe { mem :: transmute :: < _ , & bool > ( & 3u8 ) } ;
const RAW_TRAIT_OBJ_VTABLE_NULL : * const dyn Trait = unsafe { mem :: transmute ( ( & 92u8 , 0usize ) ) } ;
const RAW_TRAIT_OBJ_VTABLE_INVALID : * const dyn Trait = unsafe { mem :: transmute ( ( & 92u8 , & 3u64 ) ) } ;
const RAW_TRAIT_OBJ_CONTENT_INVALID : * const dyn Trait = unsafe { mem :: transmute :: < _ , & bool > ( & 3u8 ) } as * const dyn Trait ;
static mut RAW_TRAIT_OBJ_VTABLE_NULL_THROUGH_REF : * const dyn Trait = unsafe {
mem :: transmute :: < _ , & dyn Trait > ( ( & 92u8 , 0usize ) )
} ;
static mut RAW_TRAIT_OBJ_VTABLE_INVALID_THROUGH_REF : * const dyn Trait = unsafe {
mem :: transmute :: < _ , & dyn Trait > ( ( & 92u8 , & 3u64 ) )
} ;
fn main ( ) { }
