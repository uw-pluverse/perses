trait T {
async fn foo ( ) {
assert_eq ! ( func_specific ( ) ( ) , 42 ) ;
let foo : fn ( u8 ) -> u8 = | v : u8 | { v } ;
assert_eq ! ( foo ( 31 ) , 31 ) ;
assert_eq ! ( FOO ( 31 ) , 31 ) ;
let mut a : u32 = 0 ;
assert_eq ! ( { BAR [ 0 ] ( & mut a ) ; a } , 0 ) ;
assert_eq ! ( { BAR [ 1 ] ( & mut a ) ; a } , 1 ) ;
assert_eq ! ( { BAR [ 2 ] ( & mut a ) ; a } , 3 ) ;
assert_eq ! ( { BAR [ 3 ] ( & mut a ) ; a } , 6 ) ;
assert_eq ! ( { BAR [ 4 ] ( & mut a ) ; a } , 10 ) ;
assert_eq ! ( generic ( 0i8 ) ( ) , 1 ) ;
}
async fn bar ( & self ) { }
}
fn main ( ) { }
