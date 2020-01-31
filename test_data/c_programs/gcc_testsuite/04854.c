


extern int a[1024];

struct S { int i; } s;

void
f1 (int x, float f, int *p)
{
  int i;
 for (i = 0; i < 1024; i++)
    a[i]++;
 for (i = 0; i < 1024; i++)
    a[i]++;
 for (i = 0; i < 1024; i++)
    a[i]++;
 for (i = 0; i < 1024; i++)
    a[i]++;
 for (i = 0; i < 1024; i++)
    a[i]++;
}
