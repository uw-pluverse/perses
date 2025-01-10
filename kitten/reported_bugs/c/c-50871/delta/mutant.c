int __attribute__ ( ( target ( "sse4.2" ) ) ) foo ( void ) { return 0 ; }
int __attribute__ ( ( target ( "arch=sandybridge" ) ) ) foo ( void ) ;
int __attribute__ ( ( target ( "arch=ivybridge" ) ) ) foo ( void ) { return 1 ; }
int __attribute__ ( ( target ( "arch=goldmont" ) ) ) foo ( void ) { return 3 ; }
int __attribute__ ( ( target ( "arch=goldmont-plus" ) ) ) foo ( void ) { return 4 ; }
int __attribute__ ( ( target ( "arch=tremont" ) ) ) foo ( void ) { return 5 ; }
int __attribute__ ( ( target ( "arch=icelake-client" ) ) ) foo ( void ) { return 6 ; }
int __attribute__ ( ( target ( "arch=icelake-server" ) ) ) foo ( void ) { return 7 ; }
int __attribute__ ( ( target ( "arch=cooperlake" ) ) ) foo ( void ) { return 8 ; }
int __attribute__ ( ( target ( "arch=tigerlake" ) ) ) foo ( void ) { return 9 ; }
int __attribute__ ( ( target ( "arch=sapphirerapids" ) ) ) foo ( void ) { return 10 ; }
int __attribute__ ( ( target ( "arch=alderlake" ) ) ) foo ( void ) { return 11 ; }
int __attribute__ ( ( target ( "arch=rocketlake" ) ) ) foo ( void ) { float outer10 ;
float outer11 ;
float outer12 ;
{
extern int outer10 ;
extern float outer11 ;
static double outer12 ;
{
extern float outer12 ;
extern float outer13 ;
}
} }
int __attribute__ ( ( target ( "default" ) ) ) foo ( void ) { return 2 ; }
int bar ( ) {
return foo ( ) ;
}
inline int __attribute__ ( ( target ( "sse4.2" ) ) ) foo_inline ( void ) { return 0 ; }
inline int __attribute__ ( ( target ( "arch=sandybridge" ) ) ) foo_inline ( void ) ;
inline int __attribute__ ( ( target ( "arch=ivybridge" ) ) ) foo_inline ( void ) { return 1 ; }
inline int __attribute__ ( ( target ( "default" ) ) ) foo_inline ( void ) { return 2 ; }
int bar2 ( ) {
return foo_inline ( ) ;
}
inline __attribute__ ( ( target ( "default" ) ) ) void foo_decls ( void ) ;
inline __attribute__ ( ( target ( "sse4.2" ) ) ) void foo_decls ( void ) ;
void bar3 ( ) {
foo_decls ( ) ;
}
inline __attribute__ ( ( target ( "default" ) ) ) void foo_decls ( void ) { }
inline __attribute__ ( ( target ( "sse4.2" ) ) ) void foo_decls ( void ) { }
inline __attribute__ ( ( target ( "default" ) ) ) void foo_multi ( int i , double d ) { }
inline __attribute__ ( ( target ( "avx,sse4.2" ) ) ) void foo_multi ( int i , double d ) { }
inline __attribute__ ( ( target ( "sse4.2,fma4" ) ) ) void foo_multi ( int i , double d ) { }
inline __attribute__ ( ( target ( "arch=ivybridge,fma4,sse4.2" ) ) ) void foo_multi ( int i , double d ) { }
void bar4 ( ) {
foo_multi ( 1 , 5.0 ) ;
}
int fwd_decl_default ( void ) ;
int __attribute__ ( ( target ( "default" ) ) ) fwd_decl_default ( void ) { return 2 ; }
int fwd_decl_avx ( void ) ;
int __attribute__ ( ( target ( "avx" ) ) ) fwd_decl_avx ( void ) { return 2 ; }
int __attribute__ ( ( target ( "default" ) ) ) fwd_decl_avx ( void ) { return 2 ; }
void bar5 ( ) {
fwd_decl_default ( ) ;
fwd_decl_avx ( ) ;
}
int __attribute__ ( ( target ( "avx" ) ) ) changed_to_mv ( void ) { return 0 ; }
int __attribute__ ( ( target ( "fma4" ) ) ) changed_to_mv ( void ) { return 1 ; }
__attribute__ ( ( target ( "default" ) , used ) ) inline void foo_used ( int i , double d ) { }
__attribute__ ( ( target ( "avx,sse4.2" ) ) ) inline void foo_used ( int i , double d ) { }
__attribute__ ( ( target ( "default" ) ) ) inline void foo_used2 ( int i , double d ) { }
__attribute__ ( ( target ( "avx,sse4.2" ) , used ) ) inline void foo_used2 ( int i , double d ) { }
static void must_be_emitted ( void ) { }
inline __attribute__ ( ( target ( "default" ) ) ) void pr50025 ( void ) { must_be_emitted ( ) ; }
void calls_pr50025 ( ) { pr50025 ( ) ; }
inline __attribute__ ( ( target ( "default" ) ) ) void pr50025b ( void ) { must_be_emitted ( ) ; }
inline __attribute__ ( ( target ( "default" ) ) ) void pr50025c ( void ) { pr50025b ( ) ; }
void calls_pr50025c ( ) { pr50025c ( ) ; }
