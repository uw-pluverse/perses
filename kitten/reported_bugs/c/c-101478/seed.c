

struct list { struct list *n; };

struct obj {
    int n;
    struct list l;
} _o;

struct list _l = { .n = &_o.l };

int main(int argc, char *argv[])
{
  struct obj *o = &_o;
  _o.l.n = &_l;
  while (&o->l != &_l)






    o = ((struct obj *)((const char *)(o->l.n)
   - (const char *)&((struct obj *)0)->l));
  return 0;
}
