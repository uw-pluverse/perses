





struct s { char c[17]; };

struct s x;

struct s a, b, c;
int d;



char p[((sizeof (x.c) == 17) ? 1 : -1)];
char q[((sizeof (0, x.c) == sizeof (char *)) ? 1 : -1)];
char r0[((sizeof ((d ? b : c).c) == 17) ? 1 : -1)];
char r1[((sizeof ((d, b).c) == 17) ? 1 : -1)];
char r2[((sizeof ((a = b).c) == 17) ? 1 : -1)];

char s0[((sizeof (0, (d ? b : c).c) == sizeof (char *)) ? 1 : -1)];
char s0[((sizeof (0, (d, b).c) == sizeof (char *)) ? 1 : -1)];
char s0[((sizeof (0, (a = b).c) == sizeof (char *)) ? 1 : -1)];
