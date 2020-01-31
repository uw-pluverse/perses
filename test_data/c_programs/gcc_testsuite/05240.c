



void bar(char*, char*, int);
void foo(char* left, char* rite, int element)
{
  while (left <= rite)
  {




    rite -= element;
    bar(left, rite, element);
  }
}
