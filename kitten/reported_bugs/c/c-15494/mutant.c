void
foo ( )
{
double x = 4 , y ;
__asm__ volatile ( "" : "=r,r" ( x ) , "=r,r" ( y ) : "%0,0" ( foo ) , "m,r" ( 8 ) ) ;
}
