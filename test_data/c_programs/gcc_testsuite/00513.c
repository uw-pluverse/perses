


typedef struct s {
  int v;
  int b;
  struct s *l;
  struct s *r;
} S;


int foo(S *s)
{
  S *this;
  S *next;

  this = s;
  if (this->b)
    next = this->l;
  else
    next = this->r;

  return next->v;
}
