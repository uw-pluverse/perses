# ! [ cfg_attr ( cfg_attr , feature ( const_generics ) ) ]
# ! [ cfg_attr ( full , allow ( incomplete_features ) ) ]
# ! [ cfg_attr ( min , feature ( min_const_generics ) ) ]
pub struct MyArray < const COUNT : usize > ( [ u8 ; COUNT + 1 ] ) ;
impl < const COUNT : usize > MyArray < COUNT > {
fn inner ( & self ) -> & [ u8 ; COUNT + 1 ] {
& self . 0
}
}
fn main ( ) { }
