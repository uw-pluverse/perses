




extern void g (int);

int
f (long long d)
{
  long long c = d & 0xffffffffff;
  int i = (int) c;
  g (i);
}
