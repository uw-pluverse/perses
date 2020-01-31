




extern void exit (int);
extern void abort (void);

int
main (void)
{
  if (L"a" "b"[1] != L'b')
    abort ();
  exit (0);
}
