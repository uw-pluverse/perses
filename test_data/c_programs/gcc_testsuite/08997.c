


extern int global;
extern int global2;
extern int global3;

void foo (int base)
{
  int i;
  while (global < 10)
  {
    if(global || global2 || global3)
      return;

    for (i = base; i < 10; i++)
      if (i > 123)
 return;
  }
}
