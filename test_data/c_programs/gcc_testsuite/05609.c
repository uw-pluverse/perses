


extern void abort (void);




double p[2] = { 4., 5. };

int main()
{
  long j;
  double R, n, x;

  n = 1.e300;
  x = -1.e300;




  for( j=0; j < 2; j++ )
    {
      x = (((x)>(p[j])) ? (x) : (p[j]));
      n = (((n)<(p[j])) ? (n) : (p[j]));
    }
  R = x-n;

  if( R < 0.1 )
      abort ();

  return 0;
}
