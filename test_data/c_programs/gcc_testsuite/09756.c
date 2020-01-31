


typedef long unsigned int size_t;
extern void* malloc(size_t x);

int e[3];

struct f { int f[3]; };

extern void bar(int v[]);

struct h {

 int i;
 int j[];
};

struct h0 {

 int i;
 int j[0];
};

struct h0b {

 int i;
 int j[0];
 int k;
};

struct h1 {

 int i;
 int j[1];
};

struct h1b {

 int i;
 int j[1];
 int k;
};

struct h3 {

 int i;
 int j[3];
};

struct h3b {

 int i;
 int j[3];
 int k;
};

void foo(int (*a)[3])
{
 (*a)[4] = 1;
 a[0][0] = 1;
 a[1][0] = 1;
 a[1][4] = 1;

 int c[3] = { 0 };

 c[4] = 1;

 e[4] = 1;

 struct f f;
 f.f[4] = 1;

 struct h* h = malloc(sizeof(struct h) + 3 * sizeof(int));
 struct h0* h0 = malloc(sizeof(struct h0) + 3 * sizeof(int));
 struct h1* h1 = malloc(sizeof(struct h1) + 3 * sizeof(int));
 struct h3* h3 = malloc(sizeof(struct h3));

 h->j[4] = 1;
 h0->j[4] = 1;
 h1->j[4] = 1;
 h3->j[4] = 1;

 struct h0b* h0b = malloc(sizeof(struct h) + 3 * sizeof(int));
 struct h1b* h1b = malloc(sizeof(struct h1b) + 3 * sizeof(int));
 struct h3b* h3b = malloc(sizeof(struct h3b));

 h1b->j[4] = 1;;
 h3b->j[4] = 1;;


 bar(*a);
 bar(c);
 bar(e);
 bar(f.f);
 bar(h1->j);
 bar(h3->j);
 bar(h3b->j);
 bar(h1b->j);
 bar(h->j);
 bar(h0->j);
}
