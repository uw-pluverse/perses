pub trait StreamOnce {
type Position ;
}
impl < 'a > StreamOnce for & 'a str {
type Position = usize ;
}
pub fn parser < F > ( _ : F ) {
}
fn follow ( _ : & str ) -> < & str as StreamOnce > :: Position { String :: new
}
fn main ( ) {
parser ( follow ) ;
}
