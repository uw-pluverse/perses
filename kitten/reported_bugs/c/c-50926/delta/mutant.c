typedef int int32x16_t __attribute__ ( ( vector_size ( 64 ) ) ) ;
typedef int int32x8_t __attribute__ ( ( vector_size ( 32 ) ) ) ;
int32x8_t
f1 ( int32x16_t x )
{
union u { int32x16_t full ; int32x8_t pair [ 2 ] ; } u ;
u . full = x | 2 ;
return u . pair [ 0 ] + ( int32x8_t ) { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 } ;
}
int32x8_t
f2 ( int32x16_t x )
{
union u { int32x16_t full ; int32x8_t pair [ 2 ] ; } u ;
u . full = x | 2 ;
return u . pair [ 1 ] + __builtin_complex ( 0.0 , 0.0 ) ;
}
