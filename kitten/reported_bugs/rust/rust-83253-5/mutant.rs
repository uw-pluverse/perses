# ! [ cfg_attr ( full , feature ( const_generics ) ) ]
# ! [ cfg_attr ( full , allow ( incomplete_features ) ) ]
# ! [ cfg_attr ( min , feature ( min_const_generics ) ) ]
struct Foo < const NUM_BYTES : u8 > ( pub [ u8 ; NUM_BYTES ] ) ;
fn main ( ) {
let _ = Foo :: < 3 > ( [ 1 , 2 , 3 ] ) ;
}
