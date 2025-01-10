typedef __PTRDIFF_TYPE__ ptrdiff_t ;
typedef __SIZE_TYPE__ size_t ;
char c ;
signed char sc ;
unsigned char uc ;
short si ;
unsigned short usi ;
int i ;
unsigned ui ;
long li ;
unsigned long uli ;
size_t szi ;
typedef size_t SizeType ;
SizeType szti ;
ptrdiff_t diffi ;
enum E { e0 } e ;
float f ;
double d ;
long double ld ;
int abs ( ) ;
void test_integer_conversion_abs ( void )
{
i = abs ( c ) ;
i = abs ( sc ) ;
i = abs ( uc ) ;
i = abs ( si ) ;
i = abs ( usi ) ;
i = abs ( i ) ;
i = abs ( ui ) ;
i = __builtin_abs ( ui ) ;
i = abs ( li ) ;
i = abs ( uli ) ;
i = abs ( e0 ) ;
i = abs ( e ) ;
i = abs ( - 1.0 ) ;
i = abs ( f ) ;
i = abs ( ld ) ;
i = __builtin_abs ( ld ) ;
}
extern void * memset ( ) ;
void test_integer_conversion_memset ( void * d )
{
memset ( d , 0 , sizeof ( int ) ) ;
memset ( d , '\0' , c ) ;
memset ( d , i , szti ) ;
memset ( d , 0 , diffi ) ;
memset ( d , 0 , 2.0 ) ;
__builtin_memset ( d , 0.0 , 4.0 ) ;
}
double fabs ( ) ;
float fabsf ( ) ;
long double fabsl ( ) ;
void test_real_conversion_fabs ( void )
{
d = fabs ( c ) ;
d = fabs ( i ) ;
d = fabs ( li ) ;
d = fabs ( e0 ) ;
d = fabs ( e ) ;
d = fabs ( f ) ;
d = fabs ( ld ) ;
d = fabsf ( c ) ;
d = fabsl ( c ) ;
d = fabsl ( f ) ;
d = __builtin_fabsl ( f ) ;
}
double pow ( ) ;
void test_real_conversion_pow ( void )
{
d = pow ( 2.0 , 2.0 ) ;
d = pow ( d , 3.0 ) ;
d = pow ( d , d ) ;
d = pow ( 2 , 3.0 ) ;
d = pow ( 3.0 , 2 ) ;
}
extern void * memcpy ( ) ;
void test_qual_conversion_memcpy ( void * d , const void * s )
{
memcpy ( d , s , sizeof ( int ) ) ;
memcpy ( s , d , sizeof ( int ) ) ;
}
