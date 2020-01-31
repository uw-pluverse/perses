double a[2000000],c[2000000];
void tuned_STREAM_Copy()
{
  int j;
  for (j=0; j<2000000; j++)
    c[j] = a[j];
}
