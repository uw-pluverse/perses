


struct bah {int a,b,c,d,e;};
static struct bah bah3={2,3,4,5,6};
const static struct bah bah4={2,3,4,5,6};
void test (int, struct bah *, struct bah, struct bah, int, struct bah, struct bah, struct bah);
void foo (int invariant, struct bah invariant2)
{
  int i;
  struct bah bah2={1,2,3,4,5};
  struct bah bah5={1,2,3,4,5};
  for (i = 0; i<10; i++)
    {
      bah5.a=i;
      test (i, &bah2, bah2, bah3, invariant, invariant2, bah4, bah5);
    }
}
