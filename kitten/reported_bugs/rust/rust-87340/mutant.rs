# ! [ feature ( type_alias_impl_trait ) ]
fn main ( ) {
}
type PartiallyDefined < T > = impl 'static ;
fn partially_defined < T : std :: fmt :: Debug > ( _ : T ) -> PartiallyDefined < _ > {
4u32
}
type PartiallyDefined2 < T > = impl 'static ;
fn partially_defined2 < T : std :: fmt :: Debug > ( _ : T ) -> PartiallyDefined2 < T > {
4u32
}
fn partially_defined22 < T > ( _ : T ) -> PartiallyDefined2 < T > {
4u32
}
