#include <stdarg.h> int i exit ( int ) ;
extern void abort ( void ) ;
char a [ 1 ] ;
void
f1 ( void )
{
int i = 0 ;
int j = sizeof ( typeof ( * ( ++ i , ( char ( * ) [ i ] ) a ) ) ) ;
if ( i != 1 || j != 1 )
abort ( ) ;
}
int
main ( void )
{
f1 ( ) ;
exit ( 0 ) ;
}
