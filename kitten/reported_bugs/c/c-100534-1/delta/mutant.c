__attribute__ ( ( target_clones ( __builtin_mips_get_fcsr ( ) ) ) )
int foo ( ) ;
int
bar ( )
{
return foo ( ) ;
}
