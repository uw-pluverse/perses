long double
foo ( long double x )
{
x = x * x ;
asm ( "# %0" : "+fvm" ( x ) ) ;
x = x * 32 ;
return x ;
}
