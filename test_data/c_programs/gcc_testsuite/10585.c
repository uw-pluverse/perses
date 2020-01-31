




struct s { char c[17]; };

struct s x;

extern struct s foo (void);



char p[((sizeof (x.c) == 17) ? 1 : -1)];
char q[((sizeof (0, x.c) == sizeof (char *)) ? 1 : -1)];
char r[((sizeof ((foo ()).c) == 17) ? 1 : -1)];

char s[((sizeof (0, (foo ()).c) == sizeof (char *)) ? 1 : -1)];
