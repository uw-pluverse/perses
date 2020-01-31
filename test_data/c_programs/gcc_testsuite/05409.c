





struct example
{
  char a;
  int b;
  char c;
} *ex1;

extern void link_error(void);

void
bar (void)
{
  ex1->a = 1;
  ex1->b = 2;
  ex1->c = 3;

  if (ex1->a != 1)
    link_error ();
  if (ex1->b != 2)
    link_error ();
  if (ex1->c != 3)
    link_error ();

}

void
foo (struct example *ex2)
{
  ex2->a = 1;
  ex2->b = 2;
  ex2->c = 3;

  if (ex2->a != 1)
    link_error ();
  if (ex2->b != 2)
    link_error ();
  if (ex2->c != 3)
    link_error ();

}

int main (void)
{
  bar ();
  foo (ex1);
  return 0;
}
