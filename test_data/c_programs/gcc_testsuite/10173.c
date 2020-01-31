


typedef _Complex float C;
C foo()
{
  C f;
  __imag__ f = 0;
  return f;
}
