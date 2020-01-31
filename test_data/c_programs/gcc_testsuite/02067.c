




extern void abort (void);
extern void exit (int);

int main (void)
{
  int i;
  signed char j;
  unsigned char k;

  i = 127;

  j = ((signed char) (i << 1)) / 2;

  if (j != -1)
    abort();

  j = ((signed char) (i * 2)) / 2;

  if (j != -1)
    abort();

  i = (127*2 +1);

  k = ((unsigned char) (i << 1)) / 2;

  if (k != (127*2 +1)/2)
    abort();

  k = ((unsigned char) (i * 2)) / 2;

  if (k != (127*2 +1)/2)
    abort();

  exit(0);
}
