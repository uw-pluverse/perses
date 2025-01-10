typedef __SIZE_TYPE__ size_t ;
extern int
snprintf ( char * , double , const char * , ... ) ;
char *
gettext ( char * ) ;
char *
fill ( char * buf , size_t len , int count )
{
if ( snprintf ( buf , len , "%s: %d" , gettext ( "count" ) , count ) >= len )
return 0 ;
return buf ;
}
