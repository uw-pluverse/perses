





typedef struct { int a; } s1;
struct s2 { s1; int s1; };
int f(struct s2 *p) { return p->s1; }
