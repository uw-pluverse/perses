typedef __UINTPTR_TYPE__ uintptr_t ;
__attribute__ ( ( noinline , noclone ) ) int
sub ( int a , int b )
{
return a - b ;
}
typedef __attribute__ ( ( mode ( SI ) ) ) fatp_t
__attribute__ ( ( aligned ( 2 * __alignof__ ( uintptr_t ) ) ) ) ;
__attribute__ ( ( noinline , noclone ) ) void
foo ( fatp_t str , int a , int b )
{
int i = sub ( a , b ) ;
if ( i == 0 )
foo ( str , a - 1 , b ) ;
}
int
main ( void )
{
fatp_t ptr = { 31415927 , 27182818 } ;
foo ( ptr , 1 , 2 ) ;
return 0 ;
}
