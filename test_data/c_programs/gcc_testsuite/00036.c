


float a[32];
float b[32];
float r[32];

extern float sqrtf (float);

void t1(void)
{
 int i;

 for (i = 0; i < 32; i++)
   r[i] = a[i] / sqrtf (b[i]);
}

void t2(void)
{
 int i;

 for (i = 0; i < 32; i++)
   r[i] = sqrtf (a[i] / b[i]);
}

void t3(void)
{
 int i;

 for (i = 0; i < 32; i++)
   r[i] = sqrtf (a[i]);
}
