


extern int global;

int bar (int);

void foo (int base)
{
  int i;
  while (global < 10)
    for (i = base; i < 10; i++)
      bar (i);
}
