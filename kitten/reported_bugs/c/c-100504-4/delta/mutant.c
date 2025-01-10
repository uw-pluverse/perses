__attribute__ ( ( target_clones ( 16 ) ) )
void
foo ( void )
{
static void * p = && lab ;
asm volatile ( "" : "+m" ( p ) : : "memory" ) ;
lab : ;
}
