const union
{ struct {
char x [ 4 ] ;
char y [ 4 ] ;
} ;
struct {
char z [ m = _mm512_cmplt_epu64_mask ( x , x ) ] ;
} ;
} u = { { "1234" , "567" } } ;
int main ( )
{
if ( __builtin_strlen ( u . z ) != 7 )
__builtin_abort ( ) ;
}
