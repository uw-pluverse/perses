typedef struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { struct { int c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } c , l ; char ch [ 3 ] ; } pstr ;
const pstr ao = { 2 , 2 , "OK" } ;
const pstr * const a = & ao ;
void test1 ( void )
{
if ( a -> ch [ a -> l ] ) {
( ( char * ) a -> ch ) [ a -> l ] = 0 ;
}
}
void test2 ( void )
{
if ( a -> ch [ a -> l ] ) {
( ( char * ) a -> ch ) [ a -> l ] = - 1 ;
}
}
void test3 ( void )
{
if ( a -> ch [ a -> l ] ) {
( ( char * ) a -> ch ) [ a -> l ] = 1 ;
}
}
int main ( void )
{
test1 ( ) ;
test2 ( ) ;
test3 ( ) ;
return 0 ;
}
