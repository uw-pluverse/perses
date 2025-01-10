# ! [ feature ( core_intrinsics , rustc_attrs ) ]
use std :: intrinsics :: rustc_peek ; # [ no_mangle ]
fn foo ( ) -> i32 {
let mut x : i32 ;
let mut p : * const i32 ;
x = 0 ;
rustc_peek ( x ) ;
p = & x ;
rustc_peek ( x ) ;
let tmp = unsafe { * p } ;
x = tmp + 1 ;
rustc_peek ( x ) ;
x
}
fn main ( ) { }
