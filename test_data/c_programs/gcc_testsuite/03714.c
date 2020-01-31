

double y, z;
void foo (long x)
{
  y = *(double *) ((long *) (x - 1) + 1);
  z = *(double *) ((long *) (x - 1) + 1);
}
