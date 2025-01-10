int
foo ( void )
{
register _Complex long a asm ( "rax" ) ;
register int b asm ( "rdx" ) ;
asm ( "# %0 %1" : "=&r" ( a ) , "=r" ( b ) ) ; return - ( a / 10 ) ;
}
