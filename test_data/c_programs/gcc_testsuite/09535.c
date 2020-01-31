





struct ucharp { unsigned char *v, *l, *h; };







struct list
{
  struct list *next;
};

struct list *
alloc_list (void)
{
  static struct list l;
  return &l;
}

int one = 1;

void
foo (struct ucharp cp, struct ucharp lp, struct list **nextp)
{
  while (1)
    {
      struct list *list;
      while (((((((((lp).v+(0)) < (lp).l) || (((lp).v+(0)+1) > (lp).h))) && (__builtin_trap (), 0)), (lp).v)[(0)]) && ((((((((cp).v+(((((((((lp).v+(0)) < (lp).l) || (((lp).v+(0)+1) > (lp).h))) && (__builtin_trap (), 0)), (lp).v)[(0)]))) < (cp).l) || (((cp).v+(((((((((lp).v+(0)) < (lp).l) || (((lp).v+(0)+1) > (lp).h))) && (__builtin_trap (), 0)), (lp).v)[(0)]))+1) > (cp).h))) && (__builtin_trap (), 0)), (cp).v)[(((((((((lp).v+(0)) < (lp).l) || (((lp).v+(0)+1) > (lp).h))) && (__builtin_trap (), 0)), (lp).v)[(0)]))]))
        ++lp.v;
      list = alloc_list ();
      while (((((((((cp).v+(((((((((lp).v+(0)) < (lp).l) || (((lp).v+(0)+1) > (lp).h))) && (__builtin_trap (), 0)), (lp).v)[(0)]))) < (cp).l) || (((cp).v+(((((((((lp).v+(0)) < (lp).l) || (((lp).v+(0)+1) > (lp).h))) && (__builtin_trap (), 0)), (lp).v)[(0)]))+1) > (cp).h))) && (__builtin_trap (), 0)), (cp).v)[(((((((((lp).v+(0)) < (lp).l) || (((lp).v+(0)+1) > (lp).h))) && (__builtin_trap (), 0)), (lp).v)[(0)]))]))
        ++lp.v;
      if (((((((((lp).v+(0)) < (lp).l) || (((lp).v+(0)+1) > (lp).h))) && (__builtin_trap (), 0)), (lp).v)[(0)]) == one)
 do
   ++lp.v;
 while (((((((((lp).v+(0)) < (lp).l) || (((lp).v+(0)+1) > (lp).h))) && (__builtin_trap (), 0)), (lp).v)[(0)]) && ((((((((cp).v+(((((((((lp).v+(0)) < (lp).l) || (((lp).v+(0)+1) > (lp).h))) && (__builtin_trap (), 0)), (lp).v)[(0)]))) < (cp).l) || (((cp).v+(((((((((lp).v+(0)) < (lp).l) || (((lp).v+(0)+1) > (lp).h))) && (__builtin_trap (), 0)), (lp).v)[(0)]))+1) > (cp).h))) && (__builtin_trap (), 0)), (cp).v)[(((((((((lp).v+(0)) < (lp).l) || (((lp).v+(0)+1) > (lp).h))) && (__builtin_trap (), 0)), (lp).v)[(0)]))]));
      *nextp = list;
      nextp = &list->next;
      if (!*lp.v)
 break;
    }
}

extern void exit (int);

int
main (void)
{
  static unsigned char cp0[] = "\0\0\0\0";
  struct ucharp cp = { cp0, cp0, cp0 + sizeof (cp0) };

  static unsigned char lp0[] = "\1\1\0\0";
  struct ucharp lp = { lp0, lp0, lp0 + sizeof (lp0) };

  struct list list;
  struct list *nextp = &list;

  foo (cp, lp, &nextp);

  exit (0);
}
