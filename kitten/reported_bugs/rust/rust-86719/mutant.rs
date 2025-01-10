# ! [ feature ( type_alias_impl_trait ) ]
pub trait Bar {
type E : Copy ;
fn foo < T > ( ) -> Self :: E ;
}
impl < S : Default > Bar for S {
type E = impl Copy ;
fn foo < T : Default > ( ) -> Self :: E {
( drop ( ( 0 .. 1 ) . filter ( |_| true ) ) , T :: default ( ) )
}
}
fn main ( ) { }
