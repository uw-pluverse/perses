# ! [ feature ( type_alias_impl_trait ) ]
type X = impl Clone ;
fn bar < F : Copy > ( f : F ) -> F {
f
}
fn foo ( ) -> X {
bar ( |_| ( ) )
}
fn main ( ) { }
