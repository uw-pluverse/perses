# ! [ feature ( rustc_attrs ) ]
# ! [ allow ( warnings ) ]
fn main ( ) { }
pub trait Foo : Sized {
fn foo ( self ) { }
}
pub trait Bar : Sized {
fn bar ( self ) { }
}
mod x {
use { Foo , Bar } ;
# [ rustc_if_this_changed ]
impl Foo for char { }
impl Bar for char { }
}
mod y {
use { Foo , Bar } ;
# [ rustc_then_this_would_need ( typeck ) ]
pub fn call_bar ( ) {
char :: bar ( 'a' ) ;
}
}
mod z {
use y ;
# [ rustc_then_this_would_need ( typeck ) ]
pub fn z ( ) {
y :: call_bar ( ) ;
}
}
