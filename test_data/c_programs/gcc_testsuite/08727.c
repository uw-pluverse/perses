


static int i;


static int *p = &i;

int j;


static int *q = &j;

static int k;

int *r = &k;


int l;

int *s = &l;



int foo() { return &p < &q; }

int main()
{
  return 0;
}
