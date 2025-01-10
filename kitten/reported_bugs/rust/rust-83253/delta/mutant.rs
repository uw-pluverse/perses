# ! [ cfg_attr ( full , feature ( const_generics ) ) ]
# ! [ cfg_attr ( full , allow ( incomplete_features ) ) ]
# ! [ cfg_attr ( min , feature ( min_const_generics ) ) ]
struct X ;
impl X {
pub fn getn < const N : usize > ( & self ) -> [ u8 ; N ] {
getn :: < N > ( )
}
}
fn getn < const N : cfg_attr > ( ) -> [ u8 ; N ] {
unsafe {
std :: mem :: zeroed ( )
}
}
fn main ( ) {
let [ a , b , c ] = getn :: < 3 > ( ) ;
let [ a , b , c ] = X . getn :: < 3 > ( ) ;
let arr : [ u8 ; 3 ] = X . getn :: < 3 > ( ) ;
}
