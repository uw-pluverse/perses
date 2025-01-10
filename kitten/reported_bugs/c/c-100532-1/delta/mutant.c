void * memcpy ( void z5 [ ] , const void * , __SIZE_TYPE__ ) ;
void f ( int n , int ( * x ) [ 4 ] )
{
while ( n -- )
{
int f = x [ 0 ] [ 0 ] ;
if ( f <= 0 )
memcpy ( & x [ 1 ] , & x [ 0 ] , sizeof ( x [ 0 ] ) ) ;
else
memcpy ( & x [ f ] , & x [ 0 ] , sizeof ( x [ 0 ] ) ) ;
f = x [ 0 ] [ 2 ] ;
x [ 0 ] [ 1 ] = f ;
}
}
