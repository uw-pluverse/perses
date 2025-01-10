unsigned int a ;
unsigned int * b ;
void t ( ) ;
void reset ( )
{
asm ( "" : "=r" ( a ) : "0" ( a , 23.23 ) ) ;
}
int
main ( )
{
asm ( "" : "=r" ( a ) : "0" ( 1 ) ) ;
asm ( "" : "=r" ( b ) : "0" ( & a ) ) ;
t ( ) ;
return 0 ;
}
