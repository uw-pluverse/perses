#include "analyzer-decls.h"
extern void foo ( void ) ;
void * x , * y , * z ;
void test ( void )
{
label0 :
foo ( ) ;
label1 :
foo ( ) ;
label2 :
foo ( ) ;
x = && label0 ;
y = && label1 ;
z = && label2 ;
__analyzer_eval ( x == x ) ;
__analyzer_eval ( x == y ) ;
}
void test_2 ( int i )
{
static void * array [ ] = { && label0 , && label1 , && label2 } ;
goto * array [ i ] ;
label0 :
foo ( ) ;
label1 :
foo ( ) ;
label2 :
foo ( ) ;
}
void test_3 ( int i )
{
static const int * p = { && label0 - && label0 ,
&& label1 - && label0 ,
&& label2 - && label0 } ;
goto * ( && label0 + array [ i ] ) ;
label0 :
foo ( ) ;
label1 :
foo ( ) ;
label2 :
foo ( ) ;
}
