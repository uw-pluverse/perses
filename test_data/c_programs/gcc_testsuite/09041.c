typedef enum { a } __attribute__((packed)) t;
void f(t x) {}

int main(void)
{
  t x[2], y;
  f(x[0]);
  f(y);
  return 0;
}
