extern void abort (void);
extern void exit (int);



typedef int type32;




type32
cksum (const unsigned char *src, unsigned long size)
{
  type32 ck = 0;

  switch (size & 3)
    {
    while (size > 0)
      {
    case 0:
 ck ^= (type32)*src++ << 24;
 --size;
    case 3:
 ck ^= (type32)*src++ << 16;
 --size;
    case 2:
 ck ^= (type32)*src++ << 8;
 --size;
    case 1:
 ck ^= (type32)*src++;
 --size;
      }
    }

  return ck;
}

const char testpat[] = "The quick brown fox jumped over the lazy dog.";

int
main()
{
  type32 ck;

  ck = cksum ((const unsigned char *) testpat, sizeof (testpat));
  if (ck != 925902908)
    abort ();

  exit (0);
}
