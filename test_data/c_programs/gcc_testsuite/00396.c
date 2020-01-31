



union arg {
  int intarg;
  long double longdoublearg;
};
long double d;
int va(int n, union arg **argtable)
{
  (*argtable)[n].longdoublearg = d;
}
