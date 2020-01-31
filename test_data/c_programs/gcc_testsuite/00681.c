void foo4 (float *a, int *b) { int i; for (i = 0; i < 1024; i++) b[i] = a[i] * 4.0f; }
void foo8 (float *a, int *b) { int i; for (i = 0; i < 1024; i++) b[i] = a[i] * 8.0f; }
void foo16 (float *a, int *b) { int i; for (i = 0; i < 1024; i++) b[i] = a[i] * 16.0f; }

int ints[1024];
float floats[1024];

void
reset_ints (int *arr)
{
  int i;

  for (i = 0; i < 1024; i++)
    arr[i] = 0;
}

void
check_result (int *is, int n)
{
  int i;

  for (i = 0; i < 1024; i++)
    if (is[i] != i * n)
      __builtin_abort ();
}
int
main (void)
{
  int i;
  for (i = 0; i < 1024; i++)
    floats[i] = (float) i;

  do { reset_ints (ints); foo4 (floats, ints); check_result (ints, 4); } while (0);
  do { reset_ints (ints); foo8 (floats, ints); check_result (ints, 8); } while (0);
  do { reset_ints (ints); foo16 (floats, ints); check_result (ints, 16); } while (0);

  return 0;
}
