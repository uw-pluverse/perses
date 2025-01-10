extern char x [ ] , y [ ] , z [ ] ;
struct S ;
extern struct S s , t , u ;
int v , w ;
void
foo ( void )
{
__atomic_exchange ( & x , & y , & z , 0 ) ;
}
void
bar ( void )
{ bar ( & d ) ;
}
void
baz ( void )
{
__atomic_exchange ( & v , & t , & w , 0 ) ;
}
void
qux ( void )
{
__atomic_exchange ( & v , & w , & t , 0 ) ;
}
