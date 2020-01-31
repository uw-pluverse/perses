typedef int x;
typedef int y;
int proc(int (x));
int proc2(int x);






int proc3(int (y (x)));

int main ()
{
  proc (proc2);
  return proc3 (proc);
}
