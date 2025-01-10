void
foo ( void )
{
__asm__ ( "" : : "m" ( ( { if ( sizeof ( struct one_ms ) != 8 )
abort ( ) ; } ) ) ) ;
}
