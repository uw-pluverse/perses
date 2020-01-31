







typedef int ArrT [10][10];

void
foo (ArrT Arr, int Idx)
{
  Arr[Idx][Idx] = 1;
  Arr[Idx + 10][Idx] = 2;
}
