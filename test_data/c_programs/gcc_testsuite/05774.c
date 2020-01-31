


struct {
 int i;
 int x[128];
 int j;
} a;

int foo(int i)
{
 a.x[i] = 0;
 return a.x[i];
}
