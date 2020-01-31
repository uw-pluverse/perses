






__thread int i;
__thread int j;

extern int __tls__i;
extern int __tls__j;

int main ()
{
  int delta = ((char *)&__tls__j - (char *)&__tls__i);

  if (delta < 0)
    delta = -delta;

  return delta != 12;
}
