






int arr_base[100];

int foo(int);

void xxx(void)
{
  long iter;

  for (iter = 0; iter < 100; iter++)
    arr_base[iter] = foo (iter);
}
