struct S ;
trait Tr {
type A ;
}
impl Tr for S {
type A = S ;
}
fn f < T : Tr > ( ) {
let s = T :: A { } ;
let z = T :: A :: < u8 > { } ;
match S {
T :: A { } => { }
}
}
fn g < T : Tr < A = S > > ( ) {
let s = T :: A { } ;
let z = T :: A :: < u8 > { } ;
match S {
T :: A { } => { }
}
}
fn main ( ) {
let s = S :: A { } ;
let z = S :: A :: < f > { } ;
match S {
S :: A { } => { }
}
}
