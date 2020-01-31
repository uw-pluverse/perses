



__attribute__((noreturn,noinline)) void abrt (const char *fi, const char *fu)
{
  __builtin_abort ();
}

__attribute__((noinline)) int f (int k)
{
  return k;
}

__attribute__((noinline)) int g (int t, int k)
{
  int b;

  switch (t)
    {
    case 0:
      abrt ("../gcc-seed-programs/gcc.dg/pr33676.c", __FUNCTION__);

    case 1:
      b = f (k);
      break;

    case 2:
      b = f (k);
      break;

    case 3:
      b = f (k);
      break;

    case 4:
      b = f (k);
      break;

    default:
      abrt ("../gcc-seed-programs/gcc.dg/pr33676.c", __FUNCTION__);
    }

  return b;
}

int main (void)
{
  if (g (3, 1337) != 1337)
      abrt ("../gcc-seed-programs/gcc.dg/pr33676.c", __FUNCTION__);
  return 0;
}
