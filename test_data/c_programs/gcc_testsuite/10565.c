


extern void *memcpy (void *, const void *, long unsigned int);
extern int memcmp (const void *, const void *, long unsigned int);
extern void abort(void);

char str[9] = "1234";

void
bar (void)
{
  unsigned int temp;
  char *p = &str[2];

  memcpy (&temp, &str[1], 4);
  memcpy (p, &temp, 4);
  str[1] = '.';
}

int main()
{
  bar();
  if (memcmp (str, "1.234", 5) != 0)
    abort ();

  return 0;
}
