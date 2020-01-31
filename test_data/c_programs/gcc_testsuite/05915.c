



void abort(void);
void exit(int);

int x, y;

static void __attribute__ ((noinline))
init_xy(void)
{
  x = 3;
  y = 2;
}

void
test4(void)
{
  init_xy();
  if ((x < y ? x++ : y++) != 2)
    abort ();
}

int
main(){
  test4 ();
  exit (0);
}
