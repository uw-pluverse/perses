





extern void abort (void);

int main()
{
  float i=1;

  while (i>=0)
    --i;

  if (i != -1)
    abort();
  return 0;
}
