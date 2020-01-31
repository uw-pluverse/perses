


int a,b;
void test(char *);
static inline
int aa (void)
{
  char t[10];
  test(t);
}
static inline
int bb (void)
{
  char t[100];
  test(t);
}

int
t()
{
  if (a)
    aa();
  if (b)
    bb();
}
