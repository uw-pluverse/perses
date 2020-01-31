

void f (void);
typedef long unsigned int size_t;
void g (void *a)
{
  size_t b = (size_t) a;
  switch (b)
  {
    case 1:
    f ();
    break;
  }
}
