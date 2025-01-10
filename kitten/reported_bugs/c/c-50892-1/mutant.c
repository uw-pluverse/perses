#include "arm_mve.h"
float16x8_t
foo ( uint16x8_t a , mve_pred16_t p )
{ unsigned int i = 0 ;
unsigned int * const x [ ] = {
& p -> a ,
& p -> b ,
0
} ;
( * ( volatile unsigned int * ) ( ( x [ i ] ) )
= ( unsigned int ) ( ( unsigned int ) ( ( * ( volatile unsigned int * ) ( x [ i ] ) ) ) ) ) ;
}
float16x8_t
foo1 ( uint16x8_t a , mve_pred16_t p )
{
return vcvtq_x_n ( a , 1 , p ) ;
}
