int n;
double range ;
double bin ;
double wmean;

double f ()
{
  int i ;
  long double W = 0 ;
  for ( i = 0 ; i < n ; i ++) {
    double xi = range;
    double wi = bin;
    W += wi ;
    wmean += ( xi - wmean) * ( wi / W);
  }
}
