


extern void initialize_array (unsigned char *, int);

int
test15 (void)
{
  unsigned char a[480];

  initialize_array (a, 480);

  if (a[0] == 0x10)
    return 1;

  return 0;
}
