int a = 2 , b = 1 , c = 1 ;
int
fn1 ( )
{
int d ;
for ( ; a ; a -- )
{ {
return bar ( 5 , "" , 6 , __builtin_va_arg_pack ( ) ) ;
}
}
return 0 ;
}
int
main ( )
{
fn1 ( ) ;
if ( a != 1 )
__builtin_abort ( ) ;
return 0 ;
}
