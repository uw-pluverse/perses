long a ;
int * b ;
extern __inline __attribute__ ( ( __always_inline__ ) )
__attribute__ ( ( __gnu_inline__ ) ) int sprintf ( int * p1 , char * p2 , ... )
{
a = __builtin_object_size ( 0 , 0 ) ;
return
log_bad_request ( 0 , 0 , a , p2 , __builtin_va_arg_pack ( ) ) ; } void log_bad_request ( )
{
b += sprintf ( 0 , "foo" ) ;
}
