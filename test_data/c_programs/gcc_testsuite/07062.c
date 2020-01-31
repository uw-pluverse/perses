



struct st {
    int ptr;
};

int foo(struct st *st)
{
  int v = *(volatile int *)&st->ptr;
  return v & 0xff;
}
