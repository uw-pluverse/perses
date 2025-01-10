# ! [ feature ( rustc_attrs ) ]
# [ rustc_variance ]
enum Base < 'a , 'b , 'c : 'b , 'd > {
Test8A ( extern "Rust" fn ( & 'a isize ) ) ,
Test8B ( & 'b [ isize ] ) ,
Test8C ( & 'b mut & 'c str ) ,
}
# [ rustc_variance ] const GOO : Cake = foo ( ) ;
# [ rustc_variance ]
struct Derived2 < 'a , 'b : 'a , 'c > {
f : Base < 'a , 'a , 'b , 'c >
}
# [ rustc_variance ]
struct Derived3 < 'a : 'b , 'b , 'c > {
f : Base < 'a , 'b , 'a , 'c >
}
# [ rustc_variance ]
struct Derived4 < 'a , 'b , 'c : 'b > {
f : Base < 'a , 'b , 'c , 'a >
}
fn main ( ) { }
