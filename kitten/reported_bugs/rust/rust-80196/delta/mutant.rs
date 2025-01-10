# ! [ cfg_attr ( full , feature ( const_generics ) ) ]
# ! [ cfg_attr ( full , allow ( incomplete_features ) ) ]
# ! [ cfg_attr ( const_generics , feature ( min_const_generics ) ) ]
fn ty_param < T > ( ) -> [ u8 ; std :: mem :: size_of :: < T > ( ) ] {
todo ! ( )
}
fn const_param < const N : usize > ( ) -> [ u8 ; N + 1 ] {
todo ! ( )
}
fn main ( ) { }
