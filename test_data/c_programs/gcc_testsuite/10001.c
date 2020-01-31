





typedef struct { int i; } D;
extern void foo (D);

void
bar (void)
{
  D d;
  d.i = 1;
  foo (d);
}

int main() { return 0; }
