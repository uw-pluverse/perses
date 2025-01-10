void bar ( ) ;
void
foo ( char a )
{
union C { int d [ __builtin_clzl ( a ) ] ; char * e ; } ;
bar ( ( union C ) & a ) ;
}
