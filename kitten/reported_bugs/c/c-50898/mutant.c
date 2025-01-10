const void * invalid1 ( const int * arg ) { extern int A [ ] ;
}
int valid2 ( void ) {
return __builtin_preserve_access_index ( 1 ) ;
}
void * invalid3 ( const int * arg ) {
return __builtin_preserve_access_index ( & arg [ 1 ] ) ;
}
const void * invalid4 ( volatile const int * arg ) {
return __builtin_preserve_access_index ( arg ) ;
}
int * valid5 ( int * arg ) {
return __builtin_preserve_access_index ( arg ) ;
}
int valid6 ( const volatile int * arg ) {
return * __builtin_preserve_access_index ( arg ) ;
}
struct s { int a ; int b ; } ;
int valid7 ( struct s * arg ) {
return * __builtin_preserve_access_index ( & arg -> b ) ;
}
int valid8 ( struct s * arg ) {
return __builtin_preserve_access_index ( arg -> a + arg -> b ) ;
}
int valid9 ( struct s * arg ) {
return __builtin_preserve_access_index ( ( { arg -> a = 2 ; arg -> b = 3 ; } ) ) ;
}
