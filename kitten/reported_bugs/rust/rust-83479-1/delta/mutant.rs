mod a {
pub mod b {
pub mod c {
pub struct S < T > where
P : FnMut ( & Self :: Item ) -> bool , ;
}
}
}
macro_rules ! import {
( $ p : path ) => ( use $ p ; ) ;
}
fn f1 ( ) {
import ! { a :: b :: c :: S < u8 > }
}
fn f2 ( ) {
import ! { a :: b :: c :: S < > }
}
fn main ( ) { }
