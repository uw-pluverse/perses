void
fft (double *result, double a, double b, double c)
{
  result[0] = (a*b) + c;
  result[1] = (a*b) - c;
}
