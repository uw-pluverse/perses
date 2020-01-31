float *ptrs[20];
float results[20];
int incs[20];

void __attribute__((noinline))
foo (int n)
{
  int inc0 = incs[0], inc1 = incs[1], inc2 = incs[2], inc3 = incs[3], inc4 = incs[4], inc5 = incs[5], inc6 = incs[6], inc7 = incs[7], inc8 = incs[8], inc9 = incs[9], inc10 = incs[10], inc11 = incs[11], inc12 = incs[12], inc13 = incs[13], inc14 = incs[14], inc15 = incs[15], inc16 = incs[16], inc17 = incs[17], inc18 = incs[18], inc19 = incs[19];
  float *ptr0 = ptrs[0], result0 = 0, *ptr1 = ptrs[1], result1 = 0, *ptr2 = ptrs[2], result2 = 0, *ptr3 = ptrs[3], result3 = 0, *ptr4 = ptrs[4], result4 = 0, *ptr5 = ptrs[5], result5 = 0, *ptr6 = ptrs[6], result6 = 0, *ptr7 = ptrs[7], result7 = 0, *ptr8 = ptrs[8], result8 = 0, *ptr9 = ptrs[9], result9 = 0, *ptr10 = ptrs[10], result10 = 0, *ptr11 = ptrs[11], result11 = 0, *ptr12 = ptrs[12], result12 = 0, *ptr13 = ptrs[13], result13 = 0, *ptr14 = ptrs[14], result14 = 0, *ptr15 = ptrs[15], result15 = 0, *ptr16 = ptrs[16], result16 = 0, *ptr17 = ptrs[17], result17 = 0, *ptr18 = ptrs[18], result18 = 0, *ptr19 = ptrs[19], result19 = 0;
  while (n--)
    result0 += *ptr0, ptr0 += inc0, result1 += *ptr1, ptr1 += inc1, result2 += *ptr2, ptr2 += inc2, result3 += *ptr3, ptr3 += inc3, result4 += *ptr4, ptr4 += inc4, result5 += *ptr5, ptr5 += inc5, result6 += *ptr6, ptr6 += inc6, result7 += *ptr7, ptr7 += inc7, result8 += *ptr8, ptr8 += inc8, result9 += *ptr9, ptr9 += inc9, result10 += *ptr10, ptr10 += inc10, result11 += *ptr11, ptr11 += inc11, result12 += *ptr12, ptr12 += inc12, result13 += *ptr13, ptr13 += inc13, result14 += *ptr14, ptr14 += inc14, result15 += *ptr15, ptr15 += inc15, result16 += *ptr16, ptr16 += inc16, result17 += *ptr17, ptr17 += inc17, result18 += *ptr18, ptr18 += inc18, result19 += *ptr19, ptr19 += inc19;
  results[0] = result0, results[1] = result1, results[2] = result2, results[3] = result3, results[4] = result4, results[5] = result5, results[6] = result6, results[7] = result7, results[8] = result8, results[9] = result9, results[10] = result10, results[11] = result11, results[12] = result12, results[13] = result13, results[14] = result14, results[15] = result15, results[16] = result16, results[17] = result17, results[18] = result18, results[19] = result19;
}

float input[4 * 20];

int
main (void)
{
  int i;

  for (i = 0; i < 20; i++)
    ptrs[i] = input + i, incs[i] = i;
  for (i = 0; i < 4 * 20; i++)
    input[i] = i;
  foo (4);
  for (i = 0; i < 20; i++)
    if (results[i] != i * 4 * (4 + 1) / 2)
      return 1;
  return 0;
}
