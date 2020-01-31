


struct {
 int i;
 int x[2];
 int j;
} a;

int foo(int i)
{
 a.i = 1;
 a.j = 2;
 a.x[i] = 0;
 return a.i + a.j;
}
