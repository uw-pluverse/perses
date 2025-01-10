#include "arm_mve.h"
int16x8_t
foo ( uint64_t a , uint64_t b )
{ return __atomic_always_lock_free ( 2 , a ) ;
}
