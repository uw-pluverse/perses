typedef __SIZE_TYPE__ size_t ;
extern void * memcpy ( void * , const void a [ 2 ] , size_t ) ;
struct S
{
int n ;
void * p ;
} ;
void pr86196_c0 ( struct S * a , size_t n )
{
for ( size_t i = 0 , j = 0 ; i != n ; ++ i )
{
if ( a [ i ] . n == 0 )
{
if ( i != j )
memcpy ( & a [ j ] , & a [ i ] , sizeof ( struct S ) ) ;
++ j ;
}
}
}
void pr86196_c1 ( struct S * a , int i , int j )
{
if ( i != j )
memcpy ( & a [ j ] , & a [ i ] , sizeof ( struct S ) ) ;
}
