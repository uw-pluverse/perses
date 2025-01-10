struct S { union { union { union { union { union { union { union { union { union { double b [ 4 ] ; } a [ 18 ] ; } a [ 18 ] ; } a [ 18 ] ; } a [ 18 ] ; } a [ 18 ] ; } a [ 18 ] ; } a [ 18 ] ; } a [ 18 ] ; } a [ 18 ] ; } s , a [ 5 ] ;
void foo ( struct S ) ;
struct S bar ( struct S , struct S * , struct S ) ;
void
foo ( struct S arg )
{
}
void
baz ( void )
{
foo ( bar ( s , & a [ 1 ] , a [ 2 ] ) ) ;
}
