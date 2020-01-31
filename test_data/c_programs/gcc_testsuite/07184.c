


int a[10];

static inline int n(void) {
    long unsigned int strlen(const char *s);
    return strlen("12345");
}

void g(int *p);
void h(int p);

void bar (void *);

int* f(void) {
    int b[10];
    int i;
    struct {
       int c[10];
    } c;

    a[-1] = 0;
    a[ 0] = 0;
    a[ 1] = 0;


    a[ 9] = 0;
    a[10] = 0;
    a[11] = 0;
    bar (a);
    a[2 * n() - 11] = 1;
    a[2 * n() - 10] = 1;
    a[2 * n() - 1] = 1;
    a[2 * n() - 0] = 1;
    bar (a);

    b[-1] = 0;
    b[ 0] = 0;
    b[ 1] = 0;
    b[ 9] = 0;
    b[10] = 0;
    b[11] = 0;
    bar (b);
    b[2 * n() - 11] = 1;
    b[2 * n() - 10] = 1;
    b[2 * n() - 1] = 1;
    b[2 * n() - 0] = 1;

    c.c[-1] = 0;
    c.c[ 0] = 0;
    c.c[ 1] = 0;
    c.c[ 9] = 0;
    c.c[10] = 0;
    c.c[11] = 0;
    bar (&c);
    c.c[2 * n() - 11] = 1;
    c.c[2 * n() - 10] = 1;
    c.c[2 * n() - 1] = 1;
    c.c[2 * n() - 0] = 1;

    g(&a[8]);
    g(&a[9]);
    g(&a[10]);
    g(&a[11]);
    g(&a[-30]+10);
    g(&a[-30]+30);

    g(&b[10]);
    g(&c.c[10]);
    g(&b[11]);
    g(&c.c[11]);

    g(&a[0]);
    g(&b[0]);
    g(&c.c[0]);

    g(&a[-1]);
    g(&b[-1]);
    h(sizeof a[-1]);
    h(sizeof a[10]);
    h(sizeof b[-1]);
    h(sizeof b[10]);
    h(sizeof c.c[-1]);
    h(sizeof c.c[10]);

    if (10 < 10)
       a[10] = 0;
    if (10 < 10)
       b[10] = 0;
    if (-1 >= 0)
       c.c[-1] = 0;

    for (i = 20; i < 30; ++i)
             a[i] = 1;

    bar (b);
    bar (&c);
    return a;
}
