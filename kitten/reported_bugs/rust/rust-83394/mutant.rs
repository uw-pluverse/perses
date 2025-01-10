# ! [ allow ( non_upper_case_globals ) ] # [ rustc_layout_scalar_valid_range_start ( 1 ) ]
struct S < T > { i : u8 , t : T }
impl < T > S < T > {
fn unwrap ( self ) -> T {
self . t
}
}
# [ derive ( Copy , Clone , PartialEq , Debug ) ]
struct A ( ( u32 , u32 ) ) ;
# [ derive ( Copy , Clone , PartialEq , Debug ) ]
struct B ( u64 ) ;
pub fn main ( ) {
static Ca : S < A > = S { i : 0 , t : A ( ( 13 , 104 ) ) } ;
static Cb : S < B > = S { i : 0 , t : B ( 31337 ) } ;
assert_eq ! ( Ca . unwrap ( ) , A ( ( 13 , 104 ) ) ) ;
assert_eq ! ( Cb . unwrap ( ) , B ( 31337 ) ) ;
}
