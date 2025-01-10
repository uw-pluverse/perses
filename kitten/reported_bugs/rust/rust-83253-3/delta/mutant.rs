# ! [ cfg_attr ( full , feature ( const_generics ) ) ]
# ! [ cfg_attr ( min , feature ( min_const_generics ) ) ]
fn f < T : Copy , const N :
u32 > ( x : T ) -> [ T ; N ] { [ x ; N ] } fn g < T , const N : usize > ( x : T ) -> [ T ; N ] { [ x ; N ] } fn main ( ) { let x : [ u32 ; 5 ] = f :: < u32 , 5 > ( 3 ) ;
assert_eq ! ( x , [ 3u32 ; 5 ] ) ;
}
