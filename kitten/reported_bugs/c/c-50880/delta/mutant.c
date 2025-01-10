#include <xmmintrin.h>
void __regcall v1 ( int a , int b ) { }
void __attribute__ ( ( regcall ) ) v1b ( int a , int b ) { }
void __regcall v2 ( char a , char b ) { }
struct Small { int
__regcall ; } ; void __regcall v3 ( int a , struct Small b , int c ) { } struct Large { int a [ 5 ] ; } ; void __regcall v4 ( int a , struct Large b , int c ) { } struct HFA2 { double x , y ; } ; struct HFA4 { double w , x , y , z ; } ; struct HFA5 { double v , w , x , y , z ; } ; void __regcall hfa1 ( int a , struct HFA4 b , int c ) { } void __regcall hfa2 ( struct HFA4 a , struct HFA4 b , double c ) { } void __regcall hfa3 ( double a , double b , double c , double d , double e , struct HFA2 f ) { } void __regcall hfa4 ( struct HFA5 a ) { }
static struct HFA2 g_hfa2 ;
struct HFA2 __regcall hfa5 ( void ) { return g_hfa2 ; }
typedef float __attribute__ ( ( vector_size ( 16 ) ) ) v4f32 ;
struct HVA2 { v4f32 x , y ; } ;
struct HVA4 { v4f32 w , x , y , z ; } ;
void __regcall hva1 ( int a , struct HVA4 b , int c ) { }
void __regcall hva2 ( struct HVA4 a , struct HVA4 b , v4f32 c ) { }
void __regcall hva3 ( v4f32 a , v4f32 b , v4f32 c , v4f32 d , v4f32 e , struct HVA2 f ) { }
typedef float __attribute__ ( ( ext_vector_type ( 3 ) ) ) v3f32 ;
struct OddSizeHVA { v3f32 x , y ; } ;
void __regcall odd_size_hva ( struct OddSizeHVA a ) { }
struct HFA6 { __m128 f [ 4 ] ; } ;
struct HFA6 __regcall ret_reg_reused ( struct HFA6 a , struct HFA6 b , struct HFA6 c , struct HFA6 d ) { struct HFA6 h ; return h ; }
