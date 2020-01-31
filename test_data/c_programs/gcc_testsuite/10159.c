




extern void abort (void);

struct S
{
  char a[3];
#pragma pack(1)

 struct T
  {
    char b;
    int c;
  } d;
#pragma pack ()
 int e;
} s;

int
main ()
{
  if (sizeof (int) == 4 && sizeof (s) != 12)
    abort ();
  return 0;
}
