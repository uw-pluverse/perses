# [ derive ( Copy , Clone ) ]
union Foo {
a : isize ,
b : & 'static VTable ,
}
enum Bar {
Boo = [ unsafe { Foo { b : ( ) } . a } ; 4 ] [ 3 ] ,
}
fn main ( ) {
assert_ne ! ( Bar :: Boo as isize , 0 ) ;
}
