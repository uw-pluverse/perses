struct Invariant < 'a > {
f : & 'a mut & 'a isize
}
fn use_ < 'short , 'long > ( c : Invariant < 'long > , ... ) {
let _ : Invariant < 'short > = c ;
}
fn main ( ) { }
