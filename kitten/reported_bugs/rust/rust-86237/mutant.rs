# ! [ feature ( const_generics ) ]
# ! [ allow ( incomplete_features , unused_braces ) ]
trait Bar < T > { }
impl < T > Bar < T > for [ u8 ; { 7 } ] { }
struct Foo < T , U = [ u8 ; std :: mem :: size_of :: < T > ( ) ] > { }
impl < const N : usize > Foo < N >
where
[ u8 ; N ] : Bar < [ ( ) ; N ] > ,
{
fn foo ( ) { }
}
fn main ( ) {
Foo :: foo ( ) ;
}
