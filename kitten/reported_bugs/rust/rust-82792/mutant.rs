# ! [ allow ( unused ) ]
struct S ;
impl S {
fn func < 'a , U > ( & 'a self ) -> U {
todo ! ( )
}
}
fn dont_crash < 'a , U > ( ) -> U {
S . func :: < 'a , dont_crash > ( )
}
fn main ( ) { }
