



extern void abort();

struct st{
  int _mark;
};
unsigned long long t = ((int)(long unsigned int)&(((struct st*)16)->_mark) - 32);

int main()
{
  if (t != (unsigned long long)(int)-16)
    abort ();
  return 0;
}
