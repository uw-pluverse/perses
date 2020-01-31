



typedef _Complex float C;
C foo()
{
  C f;
  __real__ f = 0;
  __imag__ f = 0;
  return f;
}
