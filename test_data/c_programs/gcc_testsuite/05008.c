



enum E { A, B, C };
struct S { enum E e:2; };
typedef struct S TS;

int
fn0 (struct S *s)
{
  switch (s->e)
    {
    case A:
      return 1;
    case B:
      return 2;
    }
}

int
fn1 (TS *s)
{
  switch (s->e)
    {
    case A:
      return 1;
    case B:
      return 2;
    }
}
