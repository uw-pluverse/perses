# ! [ feature ( unboxed_closures ) ]
# ! [ allow ( dead_code ) ]
trait Foo < T ,
T = T > { type Output ; fn dummy ( & self , t : T , v : V ) ;
}
trait Eq < X : ? Sized > { fn same_types ( & self , x : & X ) -> bool { true } }
impl < X : ? Sized > Eq < X > for X { }
fn eq < A : ? Sized , B : ? Sized > ( ) where A : Eq < B > { }
fn test < 'a , 'b > ( ) {
eq :: < dyn Foo < ( isize , ) , Output = ( ) > , dyn Foo ( isize ) > ( ) ;
eq :: < dyn Foo < ( isize , ) , isize , Output = ( ) > , dyn Foo ( isize ) > ( ) ;
eq :: < dyn Foo < ( isize , ) , ( isize , ) , Output = ( ) > , dyn Foo ( isize ) > ( ) ;
}
fn main ( ) { }
