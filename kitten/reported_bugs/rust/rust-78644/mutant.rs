# ! [ feature ( lang_items , start , no_core ) ]
# ! [ no_core ]
# [ lang = "sized" ]
pub trait Sized { }
# [ lang = "copy" ]
pub trait Copy { }
# [ lang = "deref" ]
pub trait Deref {
type bar ;
}
# [ lang = "receiver" ]
pub trait Receiver : Deref { }
impl < 'a , T > Deref for & 'a T {
type Target = T ;
}
impl < 'a , T > Receiver for & 'a T { }
mod bar {
pub use self :: glob :: * ;
pub use self :: baz :: { foo , bar } ;
pub struct A ;
impl A {
pub fn foo ( ) { }
fn bar ( ) { }
pub fn foo2 ( & self ) { }
fn bar2 ( & self ) { }
}
trait B {
fn foo ( ) -> Self ;
}
impl B for isize { fn foo ( ) -> isize { 3 } }
pub enum Enum {
Pub
}
mod baz {
pub struct A ;
impl A {
pub fn foo ( ) { }
fn bar ( ) { }
pub fn foo2 ( & self ) { }
fn bar2 ( & self ) { }
}
pub fn foo ( ) { }
pub fn bar ( ) { }
}
extern {
fn epriv ( ) ;
pub fn epub ( ) ;
}
fn test ( ) {
self :: Enum :: Pub ;
unsafe {
epriv ( ) ;
epub ( ) ;
}
self :: baz :: A ;
self :: baz :: A :: foo ( ) ;
self :: baz :: A :: bar ( ) ;
self :: baz :: A . foo2 ( ) ;
super :: gpub ( ) ;
}
mod glob {
pub fn gpub ( ) { }
fn gpriv ( ) { }
}
}
pub fn gpub ( ) { }
fn lol ( ) {
bar :: A ;
bar :: A :: foo ( ) ;
bar :: A :: bar ( ) ;
bar :: A . foo2 ( ) ;
}
mod foo {
fn test ( ) {
:: bar :: A :: foo ( ) ;
:: bar :: A :: bar ( ) ;
:: bar :: A . foo2 ( ) ;
:: bar :: baz :: A :: foo ( ) ;
:: bar :: baz :: A :: bar ( ) ;
:: bar :: baz :: A . foo2 ( ) ;
:: bar :: baz :: A . bar2 ( ) ;
let _ : isize =
:: bar :: B :: foo ( ) ;
:: lol ( ) ;
:: bar :: Enum :: Pub ;
unsafe {
:: bar :: epriv ( ) ;
:: bar :: epub ( ) ;
}
:: bar :: foo ( ) ;
:: bar :: bar ( ) ;
:: bar :: gpub ( ) ;
:: bar :: baz :: foo ( ) ;
:: bar :: baz :: bar ( ) ;
}
fn test2 ( ) {
use bar :: baz :: { foo , bar } ;
foo ( ) ;
bar ( ) ;
}
fn test3 ( ) {
use bar :: baz ;
}
fn test4 ( ) {
use bar :: { foo , bar } ;
foo ( ) ;
bar ( ) ;
}
fn test5 ( ) {
use bar ;
bar :: foo ( ) ;
bar :: bar ( ) ;
}
impl :: bar :: B for f32 { fn foo ( ) -> f32 { 1.0 } }
}
pub mod mytest {
use self :: foo :: i :: A ;
pub mod foo {
pub use self :: i :: A as foo ;
mod i {
pub struct A ;
}
}
}
# [ start ] fn main ( _ : isize , _ : * const * const u8 ) -> isize { 3 }
