


char *ptr = 0;
char array[100];
void
f()
{
  ptr = &array[0x100000000ULL];
}
