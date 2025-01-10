void __attribute__ ( ( naked ) )
foo ( int len , char arr [ ] [ len ] , int X )
{
__asm__ volatile ( "frob r0\n" ) ;
}
