int x ;
int foo ( void )
{
return __transaction_atomic ( x + 1 ) ;
}
int bar ( void )
{
return __transaction_relaxed ( ( 0x1234567876543210LL + 0x2345678765432101LL ) << 32 ) ;
}
