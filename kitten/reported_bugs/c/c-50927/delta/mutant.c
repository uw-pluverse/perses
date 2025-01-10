//#include "Inputs/diagnose-if-warn-system-header.h"
char str[0];
void underbarName ( int a ) __attribute__ ( ( __diagnose_if__ ( a , "" , "warning" ) ) ) ;
void constCharStar ( const char * str ) __attribute__ ( ( __diagnose_if__ ( ! str [ 0 ] , "empty string not allowed" , "error" ) ) ) ;
void charStar ( char * str ) __attribute__ ( ( __diagnose_if__ ( ! str . f , "empty string not allowed" , "error" ) ) ) ;
void runConstCharStar ( ) {
constCharStar ( "foo" ) ;
charStar ( "bar" ) ;
constCharStar ( "" ) ;
charStar ( "" ) ;
}
