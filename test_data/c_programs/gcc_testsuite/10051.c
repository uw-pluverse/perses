extern void abort(void);

int val = 0xff00;

int f(void)
{
 return val;
}

unsigned char a[1];

void foo(void)
{
 a[0] = f() & 255;

 if (!a[0])
  a[0] = f() & 255;

 if (!a[0])
  a[0] = 1 + (f() & 127);
}

int main(int argc, char **argv)
{
 foo();
 if (!a[0])
  abort();

 return 0;
}
