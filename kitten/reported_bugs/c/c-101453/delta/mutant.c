extern unsigned foo ( void ) ;
extern void bar ( void ) ;
__attribute__ ( ( optimize ( 0x8080808080808080ull |
( ( unsigned __int128 ) 0x8080808080808080ull ) << 64 ) ) )
void bak ( )
{
unsigned a ;
while ( 1 )
{
a = foo ( ) ;
while ( a )
{
a &= 1 ;
bar ( ) ;
}
}
}
