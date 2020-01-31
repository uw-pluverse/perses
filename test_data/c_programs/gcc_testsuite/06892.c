



extern void abort (void);

int main (void)
{
  int x0 = ( -2147483647 - 1 );
  long x1 = 0L;
  int x2 = 0;
  int t = ( 0 || ( ( -2147483647 - 1 ) - (int) ( x0 - x1 ) ) );

  if ( t != 0 ) { x2 = t; abort(); }

  return 0;
}
