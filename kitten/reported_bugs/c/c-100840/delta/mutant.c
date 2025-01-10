int
main ( void )
{
long double res , x = 40. , y = 2. ;
asm ( "lxr\t%0,%1\n"
"\taxbr\t%0,%2"
: "=&f" ( res )
: "%f" ( x ) , "f" ( y ) ) ;
assert ( res == 42. ) ;
}
