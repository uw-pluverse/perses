


extern void bzero (void *, long unsigned int);

int foo(int len)
{
  char array[1000];
  bzero(array, len);
  return 0;
}

int main() {
  int i;
  for (i = 0; i < 1000; i++)
    {
      if (i > 990)
 foo(16);
      else
 foo(8);
    }
  return 0;
}
