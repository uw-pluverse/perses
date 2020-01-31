int main()
{
   int x[10][10];
   int (*p)[] = x;
   int i;
   for(i = 0; i < 10; ++i)
   {
       p[i][i] = i;
   }
}
void foo(int a[*][2]) {(void)a[0][1]; }
void foo1(int a[2][*]) {(void)a[0][1]; }
void foo2(int a[*][*]) {(void)a[0][1]; }
void foo3(int a[2][*][2]) {(void)a[0][1][1]; }
void foo4(int a[2][*][*]) {(void)a[0][1][1]; }
