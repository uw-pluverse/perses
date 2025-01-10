__thread int g1 ;
extern __thread int g2 ;
static __thread int g3 ;
void foo ( )
{
extern __thread int l1 ; {
volatile a_struct * a ;
volatile a_struct b ;
a = & b ;
* a = ( a_struct ) { 1 , 2 , 3 , 4 } ;
a -> e . b4 = 'c' ;
if ( a -> a != 1 || a -> b != 2 || a -> c != 3 || a -> d != 4 || a -> e . b4 != 'c' )
abort ( ) ;
exit ( 0 ) ;
}
}
