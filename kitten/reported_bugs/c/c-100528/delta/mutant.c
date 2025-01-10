int a ;
static int __attribute__ ( ( target_clones ( "default" , a + 0x12345U ) ) ) fast_clamp ( )
{ }
void
c ( )
{
a = fast_clamp ( ) ;
}
