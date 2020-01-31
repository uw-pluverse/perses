float array0[0x10], array1[0x10], array2[0x10], array3[0x10], array4[0x10], array5[0x10];
float counter0 = 0, counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0;

volatile int stop = 1;
volatile int vol;

void __attribute__((noinline))
foo (int x)
{
  float *pointer0 = array0 + x, *pointer1 = array1 + x, *pointer2 = array2 + x, *pointer3 = array3 + x, *pointer4 = array4 + x, *pointer5 = array5 + x;
  int i;

  do
    {
      counter0 += *pointer0, pointer0 += 3, counter1 += *pointer1, pointer1 += 3, counter2 += *pointer2, pointer2 += 3, counter3 += *pointer3, pointer3 += 3, counter4 += *pointer4, pointer4 += 3, counter5 += *pointer5, pointer5 += 3;
      counter0 += pointer0[x], counter1 += pointer1[x], counter2 += pointer2[x], counter3 += pointer3[x], counter4 += pointer4[x], counter5 += pointer5[x];


      {
 int addend0 = vol, addend1 = vol, addend2 = vol, addend3 = vol, addend4 = vol;
 for (i = 0; i < 10; i++)
   vol += addend0, vol += addend1, vol += addend2, vol += addend3, vol += addend4;
      }
    }
  while (!stop);
}

int
main (void)
{
  int exit_code = 0;

  array0[1] = 1.0f, array0[5] = 2.0f, array1[1] = 1.0f, array1[5] = 2.0f, array2[1] = 1.0f, array2[5] = 2.0f, array3[1] = 1.0f, array3[5] = 2.0f, array4[1] = 1.0f, array4[5] = 2.0f, array5[1] = 1.0f, array5[5] = 2.0f;
  foo (1);
  exit_code |= (counter0 != 3.0f), exit_code |= (counter1 != 3.0f), exit_code |= (counter2 != 3.0f), exit_code |= (counter3 != 3.0f), exit_code |= (counter4 != 3.0f), exit_code |= (counter5 != 3.0f);
  return exit_code;
}
