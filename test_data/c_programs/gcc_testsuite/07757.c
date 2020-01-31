


extern void fn2 (float p1, float *p2, float *p3);

float *a, *b;
void fn1 (float *p1)
{
  int i;
 for (i = 0; i < 1000; i++)
    fn2 (p1[i], a + i, b + i);
}
