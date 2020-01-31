


int *a_p;
int a[1000];

void
f(int k)
{
 int i;

 for (i=k; i<1000; i+=k) {
  a_p = &a[i];
  *a_p = 100;
        }
}
