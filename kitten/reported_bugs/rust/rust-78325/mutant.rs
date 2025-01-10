macro_rules ! define_vec {
( ) => {
extern crate std as Vec ;
}
}
define_vec ! ( ) ;
mod m {
fn check ( ) {
core :: panic ! ( ) ;
}
}
macro_rules ! define_other_core {
( ) => {
extern crate std as core ;
}
}
define_other_core ! ( ) ;
fn main ( ) { }
