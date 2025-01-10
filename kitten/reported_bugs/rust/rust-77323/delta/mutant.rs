# ! [ feature ( rustc_attrs ) ]
# ! [ allow ( dead_code ) ]
# ! [ allow ( unused_variables ) ]
fn main ( ) { }
# [ rustc_if_this_changed ]
struct WillChange {
x : u32 ,
y : u32
}
struct WontChange {
x : u32 ,
y : u32
}
mod signatures {
use WillChange ;
# [ rustc_then_this_would_need ( type_of ) ]
# [ rustc_then_this_would_need ( associated_item ) ]
# [ rustc_then_this_would_need ( trait_def ) ]
trait Bar {
# [ rustc_then_this_would_need ( fn_sig ) ]
fn do_something ( rustc_then_this_would_need : WillChange ) ;
}
# [ rustc_then_this_would_need ( fn_sig ) ]
# [ rustc_then_this_would_need ( typeck ) ]
fn some_fn ( x : WillChange ) { }
# [ rustc_then_this_would_need ( fn_sig ) ]
# [ rustc_then_this_would_need ( typeck ) ]
fn new_foo ( x : u32 , y : u32 ) -> WillChange {
WillChange { x : x , y : y }
}
# [ rustc_then_this_would_need ( type_of ) ]
impl WillChange {
# [ rustc_then_this_would_need ( fn_sig ) ]
# [ rustc_then_this_would_need ( typeck ) ]
fn new ( x : u32 , y : u32 ) -> WillChange { loop { } }
}
# [ rustc_then_this_would_need ( type_of ) ]
impl WillChange {
# [ rustc_then_this_would_need ( fn_sig ) ]
# [ rustc_then_this_would_need ( typeck ) ]
fn method ( & self , x : u32 ) { }
}
struct WillChanges {
# [ rustc_then_this_would_need ( type_of ) ]
x : WillChange ,
# [ rustc_then_this_would_need ( type_of ) ]
y : WillChange
}
# [ rustc_then_this_would_need ( type_of ) ]
fn indirect ( x : WillChanges ) { }
}
mod invalid_signatures {
use WontChange ;
# [ rustc_then_this_would_need ( type_of ) ]
trait A {
# [ rustc_then_this_would_need ( fn_sig ) ]
fn do_something_else_twice ( x : WontChange ) ;
}
# [ rustc_then_this_would_need ( fn_sig ) ]
fn b ( x : WontChange ) { }
# [ rustc_then_this_would_need ( fn_sig ) ]
# [ rustc_then_this_would_need ( typeck ) ]
fn c ( x : u32 ) { }
}
