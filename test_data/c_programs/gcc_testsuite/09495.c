


char heap[50000];



int
main ()
{
  for (unsigned ix = sizeof (heap); ix--;)
    heap[ix] = ix;
  return 0;
}
