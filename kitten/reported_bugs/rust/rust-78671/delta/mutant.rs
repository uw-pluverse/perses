# ! [ allow ( incomplete_features ) ]
# ! [ feature ( generic_associated_types ) ]
# ! [ feature ( associated_type_defaults ) ]
trait Collection < T > {
type Iter < 'iter > : Iterator < Item = & 'iter T > where T : 'iter ;
type Family : CollectionFamily ;
type Sibling < U > : Collection < U > =
< < Self as Collection < T > > :: Family as CollectionFamily > :: Member < U > ;
fn empty ( ) -> Self ;
fn add ( & mut self , value : T ) ;
fn iterate < 'iter > ( & 'iter self ) -> Self :: Iter < 'iter > ;
}
trait CollectionFamily {
type Member < T > : Collection < T , Family = Self > ;
}
struct VecFamily ;
impl CollectionFamily for VecFamily {
type Member < T > = Vec < T > ;
}
impl < T > Collection < T > for Vec < T > {
type Iter < 'iter > where T : 'iter = std :: slice :: Iter < 'iter , T > ;
type Family = VecFamily ;
fn empty ( ) -> Self {
Vec :: new ( )
}
fn add ( & mut self , value : T ) {
self . push ( value )
}
fn iterate < 'iter > ( & 'iter self ) -> Self :: Iter < 'iter > {
self . iter ( )
}
}
fn floatify < C > ( ints : & C ) -> < < C as Collection < i32 > > :: Family as CollectionFamily > :: Member < f32 >
where
C : Collection < i32 > ,
{
let mut res = < C :: Family as CollectionFamily > :: Member :: < CollectionFamily > :: empty ( ) ;
for & v in ints . iterate ( ) {
res . add ( v as f32 ) ;
}
res
}
fn use_floatify ( ) {
let a = vec ! [ 1 , 2 , 3 ] ;
let b = floatify ( & a ) ;
assert_eq ! ( Some ( & 1.0 ) , b . iterate ( ) . next ( ) ) ;
}
fn main ( ) {
use_floatify ( ) ;
}
