



static const unsigned int foo = 1;
unsigned int test( void )
{
  const volatile unsigned int *bar = &foo;
  return ( *bar );
}
