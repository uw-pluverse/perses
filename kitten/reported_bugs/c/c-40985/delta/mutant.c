int a ;
void
fn1 ( )
{
int b = 2 ;
for ( ; a ; ) __asm__ ( " # a: %x0, b: %x1" : "+d" ( a ) , "+d" ( b ) ) ;
}
