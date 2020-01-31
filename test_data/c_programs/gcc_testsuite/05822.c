


void link_error (void);

static inline void do_thing(char *s, int *p, char *q)
{

        if (s == 0 || q == 0)
                link_error ();


 if (p)
    *p = 3;
}

void __attribute__((nonnull (1, 3))) do_other_thing(char *s, int *p, char *q)
{
        do_thing(s, p, q);
}

int i;

int
main()
{
  do_other_thing ("xxx", &i, "yyy");
}
