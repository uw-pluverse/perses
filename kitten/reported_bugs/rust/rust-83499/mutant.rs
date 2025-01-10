async fn multiple_named_lifetimes < 'a , 'b > ( _ : & 'a u8 , ... ) { }
fn main ( ) {
let _ = multiple_named_lifetimes ( & 22 , & 44 ) ;
}
