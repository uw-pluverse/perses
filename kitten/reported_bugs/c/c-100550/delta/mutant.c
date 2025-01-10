void f1ia_x ( int [ ] ) ;
void f1ia_x ( int [ * ] ) ;
void f1ia_x ( int [ ] ) ;
void f1ia_x ( int [ * ] ) ;
void f1ia_x ( int a [ ] ) { ( void ) & a ; }
void f1ia_x ( int [ * ] ) ;
void f1ia1x ( int [ 1 ] ) ;
void f1ia1x ( int [ * ] ) ;
void f1ia1x ( int a [ 1 ] ) { ( void ) & a ; }
void f1ia1x ( int [ 1 ] ) ;
void f1ia1x ( int [ * ] ) ;
void f1ipx ( int * ) ;
void f1ipx ( int [ * ] ) ;
void f1ipx ( int * ) ;
void f1ipx ( int * p ) { ( void ) & p ; }
void f1ipx ( int [ * ] ) ;
void f1ipx ( int * ) ;
void f2ipx ( int * , int * ) ;
void f2ipx ( int * , int [ * ] ) ;
void f2ipx ( int * , int * ) ;
void f2ipx ( int * , int [ * ] ) ;
void f2ipx ( int * p , int * q ) { ( void ) & p ; ( void ) & q ; }
void f2ipx ( int * , int [ * ] ) ;
void f1ias2x ( int [ static 2 ] ) ;
void f1ias2x ( int [ * ] ) ;
void f1ias2x ( int [ static 2 ] ) ;
void f1ias2x ( int [ * ] ) ;
void f1ias2x ( int a [ static 2 ] ) { ( void ) & a ; }
void f1ias2x ( int [ * ] ) ;
void f1ias2x ( int [ static 2 ] ) ;
extern int nelts ;
void f1sa_var ( short [ ] ) ;
void f1sa_var ( short [ nelts ] ) ;
void f1sa_var ( short [ ] ) ;
void f1sa_var ( short [ nelts ] ) ;
void f1sa_var ( short a [ ] ) { ( void ) & a ; }
void f1sa_var ( short [ nelts ] ) ;
void f1sa_var ( short [ ] ) ;
void f1sa_expr ( int [ ] ) ;
void f1sa_expr ( int [ nelts + 1 ] ) ;
void f1sa_expr ( int [ ] ) ;
void f1sa_expr ( int [ nelts * 2 ] ) ;
void f1sa_expr ( int a [ ] ) { ( void ) & a ; }
void f1sa_expr ( int [ nelts / 3 ] ) ;
void f1sa_expr ( int [ ] ) ;
extern int f ( int ) ;
void f1ia_f ( int [ ] ) ;
void f1ia_f ( int [ f ( 1 ) ] ) ;
void f1ia_f ( int [ ] ) ;
void f1ia_f ( int [ f ( 2 ) ] ) ;
void f1ia_f ( int a [ ] ) { ( void ) & a ; }
void f1ia_f ( int [ f ( 3 ) ] ) ;
void f1ia_f ( int [ f1ipx ( 4 ) ] ) ;
void f1ia_f ( int [ ] ) ;
void f1iaf0_f1 ( int [ f ( 0 ) ] ) ;
void f1iaf0_f1 ( int [ f ( 1 ) ] ) ;
void f1iaf0_f1 ( int [ f ( 0 ) ] ) ;
void f1iaf0_f1 ( int [ f ( 1 ) ] ) ;
void f1iaf0_f1 ( int a [ f ( 0 ) ] ) { ( void ) & a ; }
void f1iaf0_f1 ( int [ f ( 1 ) ] ) ;
void f1iaf0_f1 ( int [ f ( 0 ) ] ) ;
void f1la_ ( long [ ] ) ;
void f1la_ ( long [ nelts ] ) ;
void f1la_ ( long [ ] ) ;
void f1la_ ( long a [ nelts ] )
{ ( void ) & a ; }
void f1la_ ( long [ ] ) ;
void f2ca_ ( int , char [ ] ) ;
void f2ca_ ( int n , char [ n ] ) ;
void f2ca_ ( int , char [ ] ) ;
void f2ca_ ( int n , char a [ n ] )
{ ( void ) & n ; ( void ) & a ; }
void f2ia1_f ( int n , int [ n ] ) ;
void f2ia1_f ( int , int [ f ( 0 ) ] ) ;
void f2ia1_f ( int m , int [ m ] ) ;
void f2ia1_f ( int , int [ f ( 1 ) ] ) ;
void f2ia1_f ( int x , int a [ x ] ) { ( void ) & x ; ( void ) & a ; }
void f2ia1_f ( int , int [ f ( 2 ) ] ) ;
void f2ia1_f ( int y , int [ y ] ) ;
void f2iaf_1 ( int , int [ f ( 0 ) ] ) ;
void f2iaf_1 ( int n , int [ n ] ) ;
void f2iaf_1 ( int , int [ f ( 0 ) ] ) ;
void f2iaf_1 ( int m , int [ m ] ) ;
void f2iaf_1 ( int x , int a [ f ( 0 ) ] ) { ( void ) & x ; ( void ) & a ; }
void f2iaf_1 ( int y , int [ y ] ) ;
void f3ia1 ( int n , int , int [ n ] ) ;
void f3ia1 ( int , int n , int [ n ] ) ;
void f3ia1 ( int n , int , int [ n ] ) ;
extern int g ( int ) ;
void f1iaf_g ( int [ f ( 1 ) ] ) ;
void f1iaf_g ( int [ g ( 1 ) ] ) ;
void f1iaf_g ( int [ f ( 1 ) ] ) ;
void nrf1iaf_g ( int [ f ( 1 ) ] ) ;
__attribute__ ( ( nonnull ) )
void nrf1iaf_g ( int [ g ( 1 ) ] ) ;
__attribute__ ( ( noreturn ) )
void nrf1iaf_g ( int [ f ( 1 ) ] ) ;
