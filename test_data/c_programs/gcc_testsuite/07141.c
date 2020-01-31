


int a = 0, b = 2147483647 - 1;
extern void abort(void);
int main()
{
  if (a - 1 > b + 1)
    abort();
  return 0;
}
