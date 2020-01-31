int main (int argc, char *argv[])
{
  int w = argc % (4 - 6 + 2);
  int x = argc / 0;
  int y = argc / (4 - 6 + 2);

  double z = 0.0 / 0.0 ;
  w = ((4 - 6 + 2) ? y / (4 - 6 + 2) : x);
  x = ((4 - 6 + 2) ? argc % (4 - 6 + 2): x);

  return 0;
}
