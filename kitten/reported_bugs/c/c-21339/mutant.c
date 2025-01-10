struct S { int c , * b , * e ; } ;
void e
( )
{
struct S a ;
asm volatile ( "" : "=rm" ( a ) : "0" ( 1 ) ) ;
}
