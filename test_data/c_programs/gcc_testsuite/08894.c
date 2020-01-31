


typedef int w __attribute__((mode(word)));

void b(char *a, char *b, int i)
{
  __builtin_memmove (&a[i], &b[i], sizeof(w));
}
