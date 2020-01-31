



double *copy(long double *first, long double *last, double *result)
{
 int n;
 for (n = last - first; n > 0; --n) {
  *result = *first;
  ++first;
  ++result;
 }
 return result;
}
