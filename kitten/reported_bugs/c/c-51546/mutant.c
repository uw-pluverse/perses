#include <x86intrin.h>
__attribute__ ( ( target ( "general-regs-only" ) ) )
void
foo1 ( void )
{ union {
int c [ 4 ] ;
long double d ;
} e = { { 0 , 0 , 4 } } ;
a ( e . d ) ;
}
