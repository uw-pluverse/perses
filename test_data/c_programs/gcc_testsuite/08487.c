






extern void abort(void);
extern void exit(int);

int x_a, x_b;

int main(void)
{
  x_a = 1, x_b = 2;
  if (x_a != 1 || x_b != 2)
    abort();
  exit(0);
}
