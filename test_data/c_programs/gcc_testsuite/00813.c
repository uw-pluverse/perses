


typedef void FP (int);



void
f1 (FP fp, int n)
{
  (fp) (n);
}

void
f2 (int n, FP fp)
{
  (fp) (n);
}
