


void bar (int, int, int);
void foo (int left, int rite, int element)
{
  while (left <= rite)
    {
      rite -= element;
      bar (left, rite, element);
      left += element;
    }
}
