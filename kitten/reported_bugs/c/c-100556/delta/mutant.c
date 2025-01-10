int global ;
int f2 ( )
{
return __transaction_atomic ( f ( 0xffffffffu ) == 0 )
+ __transaction_atomic ( global + 4 ) ;
}
