void
foo ( int x )
{
int var [ x ] ;
asm volatile ( "" : "+r" ( var ) ) ;
}
