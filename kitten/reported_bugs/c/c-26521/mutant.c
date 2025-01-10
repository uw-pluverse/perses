void
foo ( double x )
{
asm ( "# %0" : "+fm" ( x ) ) ;
}
