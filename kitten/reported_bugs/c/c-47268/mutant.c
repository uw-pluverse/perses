struct tuple_t
{
char
i [ 12 ] ; __int128_t i ; } __attribute__ ( ( packed , aligned ( 8 ) ) ) ; typedef struct unaligned_int128_t_ { __int128_t value ; } __attribute__ ( ( packed , aligned ( 4 ) ) ) unaligned_int128_t ; struct tuple_t p = { { 0 } , 1 } ; unaligned_int128_t * addr = ( unaligned_int128_t * ) ( & p . i ) ;
