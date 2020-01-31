


typedef long unsigned int size_t;
extern void *malloc (size_t);
extern void free (void *);
extern void abort (void);

union A
{
  int a1;
  char a2[3];
};

union B
{
  long long b1;
  union A b2;
};

struct C
{
  int c1;
  union A c2;
};

struct D
{
  int d1;
  union B d2;
};

union E
{
  struct C e1;
  char e2[3];
};

union F
{
  int f1;
  struct D f2;
};

struct G
{
  union A g1;
  char g2;
};

struct H
{
  int h1;
  union E h2;
};
int
main (void)
{
  size_t s, o, o2;

  s = sizeof (union A);
  o = 0;
  union A *a1 = malloc (s);
  union A *a2 = malloc (o + 212);
  if (__builtin_object_size (&a1->a1, 0) != (s)) abort (); if (__builtin_object_size (&a1->a1, 1) != (sizeof (a1->a1))) abort (); if (__builtin_object_size (&a1->a1, 2) != (s)) abort (); if (__builtin_object_size (&a1->a1, 3) != (sizeof (a1->a1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&a2->a1, 0) != (s)) abort (); if (__builtin_object_size (&a2->a1, 1) != (sizeof (a2->a1))) abort (); if (__builtin_object_size (&a2->a1, 2) != (s)) abort (); if (__builtin_object_size (&a2->a1, 3) != (sizeof (a2->a1))) abort ();
  free (a2);
  free (a1);
  s = sizeof (union A);
  o = 0;
  a1 = malloc (s);
  a2 = malloc (o + 212);
  if (__builtin_object_size (a1->a2, 0) != (s)) abort (); if (__builtin_object_size (a1->a2, 1) != (s)) abort (); if (__builtin_object_size (a1->a2, 2) != (s)) abort (); if (__builtin_object_size (a1->a2, 3) != (s)) abort (); if (__builtin_object_size (&a1->a2[0], 0) != (s)) abort (); if (__builtin_object_size (&a1->a2[0], 1) != (s)) abort (); if (__builtin_object_size (&a1->a2[0], 2) != (s)) abort (); if (__builtin_object_size (&a1->a2[0], 3) != (s)) abort (); if (__builtin_object_size (&a1->a2[1], 0) != ((s) - 1)) abort (); if (__builtin_object_size (&a1->a2[1], 1) != ((s) - 1)) abort (); if (__builtin_object_size (&a1->a2[1], 2) != ((s) - 1)) abort (); if (__builtin_object_size (&a1->a2[1], 3) != ((s) - 1)) abort ();
  s = o + 212;
  if (__builtin_object_size (a2->a2, 0) != (s)) abort (); if (__builtin_object_size (a2->a2, 1) != (s)) abort (); if (__builtin_object_size (a2->a2, 2) != (s)) abort (); if (__builtin_object_size (a2->a2, 3) != (s)) abort (); if (__builtin_object_size (&a2->a2[0], 0) != (s)) abort (); if (__builtin_object_size (&a2->a2[0], 1) != (s)) abort (); if (__builtin_object_size (&a2->a2[0], 2) != (s)) abort (); if (__builtin_object_size (&a2->a2[0], 3) != (s)) abort (); if (__builtin_object_size (&a2->a2[1], 0) != ((s) - 1)) abort (); if (__builtin_object_size (&a2->a2[1], 1) != ((s) - 1)) abort (); if (__builtin_object_size (&a2->a2[1], 2) != ((s) - 1)) abort (); if (__builtin_object_size (&a2->a2[1], 3) != ((s) - 1)) abort ();
  free (a2);
  free (a1);

  s = sizeof (union B);
  o = 0;
  union B *b1 = malloc (s);
  union B *b2 = malloc (o + 212);
  if (__builtin_object_size (&b1->b1, 0) != (s)) abort (); if (__builtin_object_size (&b1->b1, 1) != (sizeof (b1->b1))) abort (); if (__builtin_object_size (&b1->b1, 2) != (s)) abort (); if (__builtin_object_size (&b1->b1, 3) != (sizeof (b1->b1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&b2->b1, 0) != (s)) abort (); if (__builtin_object_size (&b2->b1, 1) != (sizeof (b2->b1))) abort (); if (__builtin_object_size (&b2->b1, 2) != (s)) abort (); if (__builtin_object_size (&b2->b1, 3) != (sizeof (b2->b1))) abort ();
  free (b2);
  free (b1);
  s = sizeof (union B);
  o = 0;
  b1 = malloc (s);
  b2 = malloc (o + 212);
  if (__builtin_object_size (&b1->b2.a1, 0) != (s)) abort (); if (__builtin_object_size (&b1->b2.a1, 1) != (sizeof (b1->b2.a1))) abort (); if (__builtin_object_size (&b1->b2.a1, 2) != (s)) abort (); if (__builtin_object_size (&b1->b2.a1, 3) != (sizeof (b1->b2.a1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&b2->b2.a1, 0) != (s)) abort (); if (__builtin_object_size (&b2->b2.a1, 1) != (sizeof (b2->b2.a1))) abort (); if (__builtin_object_size (&b2->b2.a1, 2) != (s)) abort (); if (__builtin_object_size (&b2->b2.a1, 3) != (sizeof (b2->b2.a1))) abort ();
  free (b2);
  free (b1);
  s = sizeof (union B);
  o = 0;
  b1 = malloc (s);
  b2 = malloc (o + 212);
  if (__builtin_object_size (b1->b2.a2, 0) != (s)) abort (); if (__builtin_object_size (b1->b2.a2, 1) != (s)) abort (); if (__builtin_object_size (b1->b2.a2, 2) != (s)) abort (); if (__builtin_object_size (b1->b2.a2, 3) != (s)) abort (); if (__builtin_object_size (&b1->b2.a2[0], 0) != (s)) abort (); if (__builtin_object_size (&b1->b2.a2[0], 1) != (s)) abort (); if (__builtin_object_size (&b1->b2.a2[0], 2) != (s)) abort (); if (__builtin_object_size (&b1->b2.a2[0], 3) != (s)) abort (); if (__builtin_object_size (&b1->b2.a2[1], 0) != ((s) - 1)) abort (); if (__builtin_object_size (&b1->b2.a2[1], 1) != ((s) - 1)) abort (); if (__builtin_object_size (&b1->b2.a2[1], 2) != ((s) - 1)) abort (); if (__builtin_object_size (&b1->b2.a2[1], 3) != ((s) - 1)) abort ();
  s = o + 212;
  if (__builtin_object_size (b2->b2.a2, 0) != (s)) abort (); if (__builtin_object_size (b2->b2.a2, 1) != (s)) abort (); if (__builtin_object_size (b2->b2.a2, 2) != (s)) abort (); if (__builtin_object_size (b2->b2.a2, 3) != (s)) abort (); if (__builtin_object_size (&b2->b2.a2[0], 0) != (s)) abort (); if (__builtin_object_size (&b2->b2.a2[0], 1) != (s)) abort (); if (__builtin_object_size (&b2->b2.a2[0], 2) != (s)) abort (); if (__builtin_object_size (&b2->b2.a2[0], 3) != (s)) abort (); if (__builtin_object_size (&b2->b2.a2[1], 0) != ((s) - 1)) abort (); if (__builtin_object_size (&b2->b2.a2[1], 1) != ((s) - 1)) abort (); if (__builtin_object_size (&b2->b2.a2[1], 2) != ((s) - 1)) abort (); if (__builtin_object_size (&b2->b2.a2[1], 3) != ((s) - 1)) abort ();
  free (b2);
  free (b1);

  s = sizeof (struct C);
  o = __builtin_offsetof (struct C, c2);
  struct C *c1 = malloc (s);
  struct C *c2 = malloc (o + 212);
  if (__builtin_object_size (&c1->c1, 0) != (s)) abort (); if (__builtin_object_size (&c1->c1, 1) != (sizeof (c1->c1))) abort (); if (__builtin_object_size (&c1->c1, 2) != (s)) abort (); if (__builtin_object_size (&c1->c1, 3) != (sizeof (c1->c1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&c2->c1, 0) != (s)) abort (); if (__builtin_object_size (&c2->c1, 1) != (sizeof (c2->c1))) abort (); if (__builtin_object_size (&c2->c1, 2) != (s)) abort (); if (__builtin_object_size (&c2->c1, 3) != (sizeof (c2->c1))) abort ();
  free (c2);
  free (c1);
  s = sizeof (struct C);
  o = __builtin_offsetof (struct C, c2);
  c1 = malloc (s);
  c2 = malloc (o + 212);
  if (__builtin_object_size (&c1->c2.a1, 0) != (s - o)) abort (); if (__builtin_object_size (&c1->c2.a1, 1) != (sizeof (c1->c2.a1))) abort (); if (__builtin_object_size (&c1->c2.a1, 2) != (s - o)) abort (); if (__builtin_object_size (&c1->c2.a1, 3) != (sizeof (c1->c2.a1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&c2->c2.a1, 0) != (s - o)) abort (); if (__builtin_object_size (&c2->c2.a1, 1) != (sizeof (c2->c2.a1))) abort (); if (__builtin_object_size (&c2->c2.a1, 2) != (s - o)) abort (); if (__builtin_object_size (&c2->c2.a1, 3) != (sizeof (c2->c2.a1))) abort ();
  free (c2);
  free (c1);
  s = sizeof (struct C);
  o = __builtin_offsetof (struct C, c2);
  c1 = malloc (s);
  c2 = malloc (o + 212);
  if (__builtin_object_size (c1->c2.a2, 0) != (s - o)) abort (); if (__builtin_object_size (c1->c2.a2, 1) != (s - o)) abort (); if (__builtin_object_size (c1->c2.a2, 2) != (s - o)) abort (); if (__builtin_object_size (c1->c2.a2, 3) != (s - o)) abort (); if (__builtin_object_size (&c1->c2.a2[0], 0) != (s - o)) abort (); if (__builtin_object_size (&c1->c2.a2[0], 1) != (s - o)) abort (); if (__builtin_object_size (&c1->c2.a2[0], 2) != (s - o)) abort (); if (__builtin_object_size (&c1->c2.a2[0], 3) != (s - o)) abort (); if (__builtin_object_size (&c1->c2.a2[1], 0) != ((s - o) - 1)) abort (); if (__builtin_object_size (&c1->c2.a2[1], 1) != ((s - o) - 1)) abort (); if (__builtin_object_size (&c1->c2.a2[1], 2) != ((s - o) - 1)) abort (); if (__builtin_object_size (&c1->c2.a2[1], 3) != ((s - o) - 1)) abort ();
  s = o + 212;
  if (__builtin_object_size (c2->c2.a2, 0) != (s - o)) abort (); if (__builtin_object_size (c2->c2.a2, 1) != (s - o)) abort (); if (__builtin_object_size (c2->c2.a2, 2) != (s - o)) abort (); if (__builtin_object_size (c2->c2.a2, 3) != (s - o)) abort (); if (__builtin_object_size (&c2->c2.a2[0], 0) != (s - o)) abort (); if (__builtin_object_size (&c2->c2.a2[0], 1) != (s - o)) abort (); if (__builtin_object_size (&c2->c2.a2[0], 2) != (s - o)) abort (); if (__builtin_object_size (&c2->c2.a2[0], 3) != (s - o)) abort (); if (__builtin_object_size (&c2->c2.a2[1], 0) != ((s - o) - 1)) abort (); if (__builtin_object_size (&c2->c2.a2[1], 1) != ((s - o) - 1)) abort (); if (__builtin_object_size (&c2->c2.a2[1], 2) != ((s - o) - 1)) abort (); if (__builtin_object_size (&c2->c2.a2[1], 3) != ((s - o) - 1)) abort ();
  free (c2);
  free (c1);

  s = sizeof (struct D);
  o = __builtin_offsetof (struct D, d2);
  struct D *d1 = malloc (s);
  struct D *d2 = malloc (o + 212);
  if (__builtin_object_size (&d1->d1, 0) != (s)) abort (); if (__builtin_object_size (&d1->d1, 1) != (sizeof (d1->d1))) abort (); if (__builtin_object_size (&d1->d1, 2) != (s)) abort (); if (__builtin_object_size (&d1->d1, 3) != (sizeof (d1->d1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&d2->d1, 0) != (s)) abort (); if (__builtin_object_size (&d2->d1, 1) != (sizeof (d2->d1))) abort (); if (__builtin_object_size (&d2->d1, 2) != (s)) abort (); if (__builtin_object_size (&d2->d1, 3) != (sizeof (d2->d1))) abort ();
  free (d2);
  free (d1);
  s = sizeof (struct D);
  o = __builtin_offsetof (struct D, d2);
  d1 = malloc (s);
  d2 = malloc (o + 212);
  if (__builtin_object_size (&d1->d2.b1, 0) != (s - o)) abort (); if (__builtin_object_size (&d1->d2.b1, 1) != (sizeof (d1->d2.b1))) abort (); if (__builtin_object_size (&d1->d2.b1, 2) != (s - o)) abort (); if (__builtin_object_size (&d1->d2.b1, 3) != (sizeof (d1->d2.b1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&d2->d2.b1, 0) != (s - o)) abort (); if (__builtin_object_size (&d2->d2.b1, 1) != (sizeof (d2->d2.b1))) abort (); if (__builtin_object_size (&d2->d2.b1, 2) != (s - o)) abort (); if (__builtin_object_size (&d2->d2.b1, 3) != (sizeof (d2->d2.b1))) abort ();
  free (d2);
  free (d1);
  s = sizeof (struct D);
  o = __builtin_offsetof (struct D, d2);
  d1 = malloc (s);
  d2 = malloc (o + 212);
  if (__builtin_object_size (&d1->d2.b2.a1, 0) != (s - o)) abort (); if (__builtin_object_size (&d1->d2.b2.a1, 1) != (sizeof (d1->d2.b2.a1))) abort (); if (__builtin_object_size (&d1->d2.b2.a1, 2) != (s - o)) abort (); if (__builtin_object_size (&d1->d2.b2.a1, 3) != (sizeof (d1->d2.b2.a1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&d2->d2.b2.a1, 0) != (s - o)) abort (); if (__builtin_object_size (&d2->d2.b2.a1, 1) != (sizeof (d2->d2.b2.a1))) abort (); if (__builtin_object_size (&d2->d2.b2.a1, 2) != (s - o)) abort (); if (__builtin_object_size (&d2->d2.b2.a1, 3) != (sizeof (d2->d2.b2.a1))) abort ();
  free (d2);
  free (d1);
  s = sizeof (struct D);
  o = __builtin_offsetof (struct D, d2);
  d1 = malloc (s);
  d2 = malloc (o + 212);
  if (__builtin_object_size (d1->d2.b2.a2, 0) != (s - o)) abort (); if (__builtin_object_size (d1->d2.b2.a2, 1) != (s - o)) abort (); if (__builtin_object_size (d1->d2.b2.a2, 2) != (s - o)) abort (); if (__builtin_object_size (d1->d2.b2.a2, 3) != (s - o)) abort (); if (__builtin_object_size (&d1->d2.b2.a2[0], 0) != (s - o)) abort (); if (__builtin_object_size (&d1->d2.b2.a2[0], 1) != (s - o)) abort (); if (__builtin_object_size (&d1->d2.b2.a2[0], 2) != (s - o)) abort (); if (__builtin_object_size (&d1->d2.b2.a2[0], 3) != (s - o)) abort (); if (__builtin_object_size (&d1->d2.b2.a2[1], 0) != ((s - o) - 1)) abort (); if (__builtin_object_size (&d1->d2.b2.a2[1], 1) != ((s - o) - 1)) abort (); if (__builtin_object_size (&d1->d2.b2.a2[1], 2) != ((s - o) - 1)) abort (); if (__builtin_object_size (&d1->d2.b2.a2[1], 3) != ((s - o) - 1)) abort ();
  s = o + 212;
  if (__builtin_object_size (d2->d2.b2.a2, 0) != (s - o)) abort (); if (__builtin_object_size (d2->d2.b2.a2, 1) != (s - o)) abort (); if (__builtin_object_size (d2->d2.b2.a2, 2) != (s - o)) abort (); if (__builtin_object_size (d2->d2.b2.a2, 3) != (s - o)) abort (); if (__builtin_object_size (&d2->d2.b2.a2[0], 0) != (s - o)) abort (); if (__builtin_object_size (&d2->d2.b2.a2[0], 1) != (s - o)) abort (); if (__builtin_object_size (&d2->d2.b2.a2[0], 2) != (s - o)) abort (); if (__builtin_object_size (&d2->d2.b2.a2[0], 3) != (s - o)) abort (); if (__builtin_object_size (&d2->d2.b2.a2[1], 0) != ((s - o) - 1)) abort (); if (__builtin_object_size (&d2->d2.b2.a2[1], 1) != ((s - o) - 1)) abort (); if (__builtin_object_size (&d2->d2.b2.a2[1], 2) != ((s - o) - 1)) abort (); if (__builtin_object_size (&d2->d2.b2.a2[1], 3) != ((s - o) - 1)) abort ();
  free (d2);
  free (d1);

  s = sizeof (union E);
  o = __builtin_offsetof (union E, e1.c2);
  union E *e1 = malloc (s);
  union E *e2 = malloc (o + 212);
  if (__builtin_object_size (&e1->e1.c1, 0) != (s)) abort (); if (__builtin_object_size (&e1->e1.c1, 1) != (sizeof (e1->e1.c1))) abort (); if (__builtin_object_size (&e1->e1.c1, 2) != (s)) abort (); if (__builtin_object_size (&e1->e1.c1, 3) != (sizeof (e1->e1.c1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&e2->e1.c1, 0) != (s)) abort (); if (__builtin_object_size (&e2->e1.c1, 1) != (sizeof (e2->e1.c1))) abort (); if (__builtin_object_size (&e2->e1.c1, 2) != (s)) abort (); if (__builtin_object_size (&e2->e1.c1, 3) != (sizeof (e2->e1.c1))) abort ();
  free (e2);
  free (e1);
  s = sizeof (union E);
  o = __builtin_offsetof (union E, e1.c2);
  e1 = malloc (s);
  e2 = malloc (o + 212);
  if (__builtin_object_size (&e1->e1.c2.a1, 0) != (s - o)) abort (); if (__builtin_object_size (&e1->e1.c2.a1, 1) != (sizeof (e1->e1.c2.a1))) abort (); if (__builtin_object_size (&e1->e1.c2.a1, 2) != (s - o)) abort (); if (__builtin_object_size (&e1->e1.c2.a1, 3) != (sizeof (e1->e1.c2.a1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&e2->e1.c2.a1, 0) != (s - o)) abort (); if (__builtin_object_size (&e2->e1.c2.a1, 1) != (sizeof (e2->e1.c2.a1))) abort (); if (__builtin_object_size (&e2->e1.c2.a1, 2) != (s - o)) abort (); if (__builtin_object_size (&e2->e1.c2.a1, 3) != (sizeof (e2->e1.c2.a1))) abort ();
  free (e2);
  free (e1);
  s = sizeof (union E);
  o = __builtin_offsetof (union E, e1.c2);
  e1 = malloc (s);
  e2 = malloc (o + 212);
  if (__builtin_object_size (e1->e1.c2.a2, 0) != (s - o)) abort (); if (__builtin_object_size (e1->e1.c2.a2, 1) != (s - o)) abort (); if (__builtin_object_size (e1->e1.c2.a2, 2) != (s - o)) abort (); if (__builtin_object_size (e1->e1.c2.a2, 3) != (s - o)) abort (); if (__builtin_object_size (&e1->e1.c2.a2[0], 0) != (s - o)) abort (); if (__builtin_object_size (&e1->e1.c2.a2[0], 1) != (s - o)) abort (); if (__builtin_object_size (&e1->e1.c2.a2[0], 2) != (s - o)) abort (); if (__builtin_object_size (&e1->e1.c2.a2[0], 3) != (s - o)) abort (); if (__builtin_object_size (&e1->e1.c2.a2[1], 0) != ((s - o) - 1)) abort (); if (__builtin_object_size (&e1->e1.c2.a2[1], 1) != ((s - o) - 1)) abort (); if (__builtin_object_size (&e1->e1.c2.a2[1], 2) != ((s - o) - 1)) abort (); if (__builtin_object_size (&e1->e1.c2.a2[1], 3) != ((s - o) - 1)) abort ();
  s = o + 212;
  if (__builtin_object_size (e2->e1.c2.a2, 0) != (s - o)) abort (); if (__builtin_object_size (e2->e1.c2.a2, 1) != (s - o)) abort (); if (__builtin_object_size (e2->e1.c2.a2, 2) != (s - o)) abort (); if (__builtin_object_size (e2->e1.c2.a2, 3) != (s - o)) abort (); if (__builtin_object_size (&e2->e1.c2.a2[0], 0) != (s - o)) abort (); if (__builtin_object_size (&e2->e1.c2.a2[0], 1) != (s - o)) abort (); if (__builtin_object_size (&e2->e1.c2.a2[0], 2) != (s - o)) abort (); if (__builtin_object_size (&e2->e1.c2.a2[0], 3) != (s - o)) abort (); if (__builtin_object_size (&e2->e1.c2.a2[1], 0) != ((s - o) - 1)) abort (); if (__builtin_object_size (&e2->e1.c2.a2[1], 1) != ((s - o) - 1)) abort (); if (__builtin_object_size (&e2->e1.c2.a2[1], 2) != ((s - o) - 1)) abort (); if (__builtin_object_size (&e2->e1.c2.a2[1], 3) != ((s - o) - 1)) abort ();
  free (e2);
  free (e1);
  s = sizeof (union E);
  o = __builtin_offsetof (union E, e1.c2);
  e1 = malloc (s);
  e2 = malloc (o + 212);
  if (__builtin_object_size (e1->e2, 0) != (s)) abort (); if (__builtin_object_size (e1->e2, 1) != (s)) abort (); if (__builtin_object_size (e1->e2, 2) != (s)) abort (); if (__builtin_object_size (e1->e2, 3) != (s)) abort (); if (__builtin_object_size (&e1->e2[0], 0) != (s)) abort (); if (__builtin_object_size (&e1->e2[0], 1) != (s)) abort (); if (__builtin_object_size (&e1->e2[0], 2) != (s)) abort (); if (__builtin_object_size (&e1->e2[0], 3) != (s)) abort (); if (__builtin_object_size (&e1->e2[1], 0) != ((s) - 1)) abort (); if (__builtin_object_size (&e1->e2[1], 1) != ((s) - 1)) abort (); if (__builtin_object_size (&e1->e2[1], 2) != ((s) - 1)) abort (); if (__builtin_object_size (&e1->e2[1], 3) != ((s) - 1)) abort ();
  s = o + 212;
  if (__builtin_object_size (e2->e2, 0) != (s)) abort (); if (__builtin_object_size (e2->e2, 1) != (s)) abort (); if (__builtin_object_size (e2->e2, 2) != (s)) abort (); if (__builtin_object_size (e2->e2, 3) != (s)) abort (); if (__builtin_object_size (&e2->e2[0], 0) != (s)) abort (); if (__builtin_object_size (&e2->e2[0], 1) != (s)) abort (); if (__builtin_object_size (&e2->e2[0], 2) != (s)) abort (); if (__builtin_object_size (&e2->e2[0], 3) != (s)) abort (); if (__builtin_object_size (&e2->e2[1], 0) != ((s) - 1)) abort (); if (__builtin_object_size (&e2->e2[1], 1) != ((s) - 1)) abort (); if (__builtin_object_size (&e2->e2[1], 2) != ((s) - 1)) abort (); if (__builtin_object_size (&e2->e2[1], 3) != ((s) - 1)) abort ();
  free (e2);
  free (e1);

  s = sizeof (union F);
  o = __builtin_offsetof (union F, f2.d2);
  union F *f1 = malloc (s);
  union F *f2 = malloc (o + 212);
  if (__builtin_object_size (&f1->f1, 0) != (s)) abort (); if (__builtin_object_size (&f1->f1, 1) != (sizeof (f1->f1))) abort (); if (__builtin_object_size (&f1->f1, 2) != (s)) abort (); if (__builtin_object_size (&f1->f1, 3) != (sizeof (f1->f1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&f2->f1, 0) != (s)) abort (); if (__builtin_object_size (&f2->f1, 1) != (sizeof (f2->f1))) abort (); if (__builtin_object_size (&f2->f1, 2) != (s)) abort (); if (__builtin_object_size (&f2->f1, 3) != (sizeof (f2->f1))) abort ();
  free (f2);
  free (f1);
  s = sizeof (union F);
  o = __builtin_offsetof (union F, f2.d2);
  f1 = malloc (s);
  f2 = malloc (o + 212);
  if (__builtin_object_size (&f1->f2.d1, 0) != (s)) abort (); if (__builtin_object_size (&f1->f2.d1, 1) != (sizeof (f1->f2.d1))) abort (); if (__builtin_object_size (&f1->f2.d1, 2) != (s)) abort (); if (__builtin_object_size (&f1->f2.d1, 3) != (sizeof (f1->f2.d1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&f2->f2.d1, 0) != (s)) abort (); if (__builtin_object_size (&f2->f2.d1, 1) != (sizeof (f2->f2.d1))) abort (); if (__builtin_object_size (&f2->f2.d1, 2) != (s)) abort (); if (__builtin_object_size (&f2->f2.d1, 3) != (sizeof (f2->f2.d1))) abort ();
  free (f2);
  free (f1);
  s = sizeof (union F);
  o = __builtin_offsetof (union F, f2.d2);
  f1 = malloc (s);
  f2 = malloc (o + 212);
  if (__builtin_object_size (&f1->f2.d2.b1, 0) != (s - o)) abort (); if (__builtin_object_size (&f1->f2.d2.b1, 1) != (sizeof (f1->f2.d2.b1))) abort (); if (__builtin_object_size (&f1->f2.d2.b1, 2) != (s - o)) abort (); if (__builtin_object_size (&f1->f2.d2.b1, 3) != (sizeof (f1->f2.d2.b1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&f2->f2.d2.b1, 0) != (s - o)) abort (); if (__builtin_object_size (&f2->f2.d2.b1, 1) != (sizeof (f2->f2.d2.b1))) abort (); if (__builtin_object_size (&f2->f2.d2.b1, 2) != (s - o)) abort (); if (__builtin_object_size (&f2->f2.d2.b1, 3) != (sizeof (f2->f2.d2.b1))) abort ();
  free (f2);
  free (f1);
  s = sizeof (union F);
  o = __builtin_offsetof (union F, f2.d2);
  f1 = malloc (s);
  f2 = malloc (o + 212);
  if (__builtin_object_size (&f1->f2.d2.b2.a1, 0) != (s - o)) abort (); if (__builtin_object_size (&f1->f2.d2.b2.a1, 1) != (sizeof (f1->f2.d2.b2.a1))) abort (); if (__builtin_object_size (&f1->f2.d2.b2.a1, 2) != (s - o)) abort (); if (__builtin_object_size (&f1->f2.d2.b2.a1, 3) != (sizeof (f1->f2.d2.b2.a1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&f2->f2.d2.b2.a1, 0) != (s - o)) abort (); if (__builtin_object_size (&f2->f2.d2.b2.a1, 1) != (sizeof (f2->f2.d2.b2.a1))) abort (); if (__builtin_object_size (&f2->f2.d2.b2.a1, 2) != (s - o)) abort (); if (__builtin_object_size (&f2->f2.d2.b2.a1, 3) != (sizeof (f2->f2.d2.b2.a1))) abort ();
  free (f2);
  free (f1);
  s = sizeof (union F);
  o = __builtin_offsetof (union F, f2.d2);
  f1 = malloc (s);
  f2 = malloc (o + 212);
  if (__builtin_object_size (f1->f2.d2.b2.a2, 0) != (s - o)) abort (); if (__builtin_object_size (f1->f2.d2.b2.a2, 1) != (s - o)) abort (); if (__builtin_object_size (f1->f2.d2.b2.a2, 2) != (s - o)) abort (); if (__builtin_object_size (f1->f2.d2.b2.a2, 3) != (s - o)) abort (); if (__builtin_object_size (&f1->f2.d2.b2.a2[0], 0) != (s - o)) abort (); if (__builtin_object_size (&f1->f2.d2.b2.a2[0], 1) != (s - o)) abort (); if (__builtin_object_size (&f1->f2.d2.b2.a2[0], 2) != (s - o)) abort (); if (__builtin_object_size (&f1->f2.d2.b2.a2[0], 3) != (s - o)) abort (); if (__builtin_object_size (&f1->f2.d2.b2.a2[1], 0) != ((s - o) - 1)) abort (); if (__builtin_object_size (&f1->f2.d2.b2.a2[1], 1) != ((s - o) - 1)) abort (); if (__builtin_object_size (&f1->f2.d2.b2.a2[1], 2) != ((s - o) - 1)) abort (); if (__builtin_object_size (&f1->f2.d2.b2.a2[1], 3) != ((s - o) - 1)) abort ();
  s = o + 212;
  if (__builtin_object_size (f2->f2.d2.b2.a2, 0) != (s - o)) abort (); if (__builtin_object_size (f2->f2.d2.b2.a2, 1) != (s - o)) abort (); if (__builtin_object_size (f2->f2.d2.b2.a2, 2) != (s - o)) abort (); if (__builtin_object_size (f2->f2.d2.b2.a2, 3) != (s - o)) abort (); if (__builtin_object_size (&f2->f2.d2.b2.a2[0], 0) != (s - o)) abort (); if (__builtin_object_size (&f2->f2.d2.b2.a2[0], 1) != (s - o)) abort (); if (__builtin_object_size (&f2->f2.d2.b2.a2[0], 2) != (s - o)) abort (); if (__builtin_object_size (&f2->f2.d2.b2.a2[0], 3) != (s - o)) abort (); if (__builtin_object_size (&f2->f2.d2.b2.a2[1], 0) != ((s - o) - 1)) abort (); if (__builtin_object_size (&f2->f2.d2.b2.a2[1], 1) != ((s - o) - 1)) abort (); if (__builtin_object_size (&f2->f2.d2.b2.a2[1], 2) != ((s - o) - 1)) abort (); if (__builtin_object_size (&f2->f2.d2.b2.a2[1], 3) != ((s - o) - 1)) abort ();
  free (f2);
  free (f1);

  s = sizeof (struct G);
  o = __builtin_offsetof (struct G, g2);
  struct G *g1 = malloc (s);
  struct G *g2 = malloc (o + 212);
  if (__builtin_object_size (&g1->g1.a1, 0) != (s)) abort (); if (__builtin_object_size (&g1->g1.a1, 1) != (sizeof (g1->g1.a1))) abort (); if (__builtin_object_size (&g1->g1.a1, 2) != (s)) abort (); if (__builtin_object_size (&g1->g1.a1, 3) != (sizeof (g1->g1.a1))) abort ();
  s = o + 212;
  if (__builtin_object_size (&g2->g1.a1, 0) != (s)) abort (); if (__builtin_object_size (&g2->g1.a1, 1) != (sizeof (g2->g1.a1))) abort (); if (__builtin_object_size (&g2->g1.a1, 2) != (s)) abort (); if (__builtin_object_size (&g2->g1.a1, 3) != (sizeof (g2->g1.a1))) abort ();
  free (g2);
  free (g1);
  s = sizeof (struct G);
  o = __builtin_offsetof (struct G, g2);
  g1 = malloc (s);
  g2 = malloc (o + 212);
  if (__builtin_object_size (g1->g1.a2, 0) != (s)) abort (); if (__builtin_object_size (g1->g1.a2, 1) != (sizeof (g1->g1.a2))) abort (); if (__builtin_object_size (g1->g1.a2, 2) != (s)) abort (); if (__builtin_object_size (g1->g1.a2, 3) != (sizeof (g1->g1.a2))) abort (); if (__builtin_object_size (&g1->g1.a2[0], 0) != (s)) abort (); if (__builtin_object_size (&g1->g1.a2[0], 1) != (sizeof (g1->g1.a2))) abort (); if (__builtin_object_size (&g1->g1.a2[0], 2) != (s)) abort (); if (__builtin_object_size (&g1->g1.a2[0], 3) != (sizeof (g1->g1.a2))) abort (); if (__builtin_object_size (&g1->g1.a2[1], 0) != ((s) - 1)) abort (); if (__builtin_object_size (&g1->g1.a2[1], 1) != ((sizeof (g1->g1.a2)) - 1)) abort (); if (__builtin_object_size (&g1->g1.a2[1], 2) != ((s) - 1)) abort (); if (__builtin_object_size (&g1->g1.a2[1], 3) != ((sizeof (g1->g1.a2)) - 1)) abort ();
  s = o + 212;
  if (__builtin_object_size (g2->g1.a2, 0) != (s)) abort (); if (__builtin_object_size (g2->g1.a2, 1) != (sizeof (g1->g1.a2))) abort (); if (__builtin_object_size (g2->g1.a2, 2) != (s)) abort (); if (__builtin_object_size (g2->g1.a2, 3) != (sizeof (g1->g1.a2))) abort (); if (__builtin_object_size (&g2->g1.a2[0], 0) != (s)) abort (); if (__builtin_object_size (&g2->g1.a2[0], 1) != (sizeof (g1->g1.a2))) abort (); if (__builtin_object_size (&g2->g1.a2[0], 2) != (s)) abort (); if (__builtin_object_size (&g2->g1.a2[0], 3) != (sizeof (g1->g1.a2))) abort (); if (__builtin_object_size (&g2->g1.a2[1], 0) != ((s) - 1)) abort (); if (__builtin_object_size (&g2->g1.a2[1], 1) != ((sizeof (g1->g1.a2)) - 1)) abort (); if (__builtin_object_size (&g2->g1.a2[1], 2) != ((s) - 1)) abort (); if (__builtin_object_size (&g2->g1.a2[1], 3) != ((sizeof (g1->g1.a2)) - 1)) abort ();
  free (g2);
  free (g1);
  s = sizeof (struct G);
  o = __builtin_offsetof (struct G, g2);
  g1 = malloc (s);
  g2 = malloc (o + 212);
  if (__builtin_object_size (&g1->g2, 0) != (s - o)) abort (); if (__builtin_object_size (&g1->g2, 1) != (sizeof (g1->g2))) abort (); if (__builtin_object_size (&g1->g2, 2) != (s - o)) abort (); if (__builtin_object_size (&g1->g2, 3) != (sizeof (g1->g2))) abort ();
  s = o + 212;
  if (__builtin_object_size (&g2->g2, 0) != (s - o)) abort (); if (__builtin_object_size (&g2->g2, 1) != (sizeof (g2->g2))) abort (); if (__builtin_object_size (&g2->g2, 2) != (s - o)) abort (); if (__builtin_object_size (&g2->g2, 3) != (sizeof (g2->g2))) abort ();
  free (g2);
  free (g1);

  s = sizeof (struct H);
  o = __builtin_offsetof (struct H, h2);
  o2 = __builtin_offsetof (struct H, h2.e1.c2);
  struct H *h1 = malloc (s);
  struct H *h2 = malloc (o2 + 212);
  if (__builtin_object_size (&h1->h1, 0) != (s)) abort (); if (__builtin_object_size (&h1->h1, 1) != (sizeof (h1->h1))) abort (); if (__builtin_object_size (&h1->h1, 2) != (s)) abort (); if (__builtin_object_size (&h1->h1, 3) != (sizeof (h1->h1))) abort ();
  s = o2 + 212;
  if (__builtin_object_size (&h2->h1, 0) != (s)) abort (); if (__builtin_object_size (&h2->h1, 1) != (sizeof (h2->h1))) abort (); if (__builtin_object_size (&h2->h1, 2) != (s)) abort (); if (__builtin_object_size (&h2->h1, 3) != (sizeof (h2->h1))) abort ();
  free (h2);
  free (h1);
  s = sizeof (struct H);
  o = __builtin_offsetof (struct H, h2);
  o2 = __builtin_offsetof (struct H, h2.e1.c2);
  h1 = malloc (s);
  h2 = malloc (o2 + 212);
  if (__builtin_object_size (&h1->h2.e1.c1, 0) != (s - o)) abort (); if (__builtin_object_size (&h1->h2.e1.c1, 1) != (sizeof (h1->h2.e1.c1))) abort (); if (__builtin_object_size (&h1->h2.e1.c1, 2) != (s - o)) abort (); if (__builtin_object_size (&h1->h2.e1.c1, 3) != (sizeof (h1->h2.e1.c1))) abort ();
  s = o2 + 212;
  if (__builtin_object_size (&h2->h2.e1.c1, 0) != (s - o)) abort (); if (__builtin_object_size (&h2->h2.e1.c1, 1) != (sizeof (h2->h2.e1.c1))) abort (); if (__builtin_object_size (&h2->h2.e1.c1, 2) != (s - o)) abort (); if (__builtin_object_size (&h2->h2.e1.c1, 3) != (sizeof (h2->h2.e1.c1))) abort ();
  free (h2);
  free (h1);
  s = sizeof (struct H);
  o = __builtin_offsetof (struct H, h2);
  o2 = __builtin_offsetof (struct H, h2.e1.c2);
  h1 = malloc (s);
  h2 = malloc (o2 + 212);
  if (__builtin_object_size (&h1->h2.e1.c2.a1, 0) != (s - o2)) abort (); if (__builtin_object_size (&h1->h2.e1.c2.a1, 1) != (sizeof (h1->h2.e1.c2.a1))) abort (); if (__builtin_object_size (&h1->h2.e1.c2.a1, 2) != (s - o2)) abort (); if (__builtin_object_size (&h1->h2.e1.c2.a1, 3) != (sizeof (h1->h2.e1.c2.a1))) abort ();
  s = o2 + 212;
  if (__builtin_object_size (&h2->h2.e1.c2.a1, 0) != (s - o2)) abort (); if (__builtin_object_size (&h2->h2.e1.c2.a1, 1) != (sizeof (h2->h2.e1.c2.a1))) abort (); if (__builtin_object_size (&h2->h2.e1.c2.a1, 2) != (s - o2)) abort (); if (__builtin_object_size (&h2->h2.e1.c2.a1, 3) != (sizeof (h2->h2.e1.c2.a1))) abort ();
  free (h2);
  free (h1);
  s = sizeof (struct H);
  o = __builtin_offsetof (struct H, h2);
  o2 = __builtin_offsetof (struct H, h2.e1.c2);
  h1 = malloc (s);
  h2 = malloc (o2 + 212);
  if (__builtin_object_size (h1->h2.e1.c2.a2, 0) != (s - o2)) abort (); if (__builtin_object_size (h1->h2.e1.c2.a2, 1) != (sizeof (h1->h2.e1.c2.a2))) abort (); if (__builtin_object_size (h1->h2.e1.c2.a2, 2) != (s - o2)) abort (); if (__builtin_object_size (h1->h2.e1.c2.a2, 3) != (sizeof (h1->h2.e1.c2.a2))) abort (); if (__builtin_object_size (&h1->h2.e1.c2.a2[0], 0) != (s - o2)) abort (); if (__builtin_object_size (&h1->h2.e1.c2.a2[0], 1) != (sizeof (h1->h2.e1.c2.a2))) abort (); if (__builtin_object_size (&h1->h2.e1.c2.a2[0], 2) != (s - o2)) abort (); if (__builtin_object_size (&h1->h2.e1.c2.a2[0], 3) != (sizeof (h1->h2.e1.c2.a2))) abort (); if (__builtin_object_size (&h1->h2.e1.c2.a2[1], 0) != ((s - o2) - 1)) abort (); if (__builtin_object_size (&h1->h2.e1.c2.a2[1], 1) != ((sizeof (h1->h2.e1.c2.a2)) - 1)) abort (); if (__builtin_object_size (&h1->h2.e1.c2.a2[1], 2) != ((s - o2) - 1)) abort (); if (__builtin_object_size (&h1->h2.e1.c2.a2[1], 3) != ((sizeof (h1->h2.e1.c2.a2)) - 1)) abort ();
  s = o2 + 212;
  if (__builtin_object_size (h2->h2.e1.c2.a2, 0) != (s - o2)) abort (); if (__builtin_object_size (h2->h2.e1.c2.a2, 1) != (sizeof (h2->h2.e1.c2.a2))) abort (); if (__builtin_object_size (h2->h2.e1.c2.a2, 2) != (s - o2)) abort (); if (__builtin_object_size (h2->h2.e1.c2.a2, 3) != (sizeof (h2->h2.e1.c2.a2))) abort (); if (__builtin_object_size (&h2->h2.e1.c2.a2[0], 0) != (s - o2)) abort (); if (__builtin_object_size (&h2->h2.e1.c2.a2[0], 1) != (sizeof (h2->h2.e1.c2.a2))) abort (); if (__builtin_object_size (&h2->h2.e1.c2.a2[0], 2) != (s - o2)) abort (); if (__builtin_object_size (&h2->h2.e1.c2.a2[0], 3) != (sizeof (h2->h2.e1.c2.a2))) abort (); if (__builtin_object_size (&h2->h2.e1.c2.a2[1], 0) != ((s - o2) - 1)) abort (); if (__builtin_object_size (&h2->h2.e1.c2.a2[1], 1) != ((sizeof (h2->h2.e1.c2.a2)) - 1)) abort (); if (__builtin_object_size (&h2->h2.e1.c2.a2[1], 2) != ((s - o2) - 1)) abort (); if (__builtin_object_size (&h2->h2.e1.c2.a2[1], 3) != ((sizeof (h2->h2.e1.c2.a2)) - 1)) abort ();
  free (h2);
  free (h1);
  s = sizeof (struct H);
  o = __builtin_offsetof (struct H, h2);
  o2 = __builtin_offsetof (struct H, h2.e1.c2);
  h1 = malloc (s);
  h2 = malloc (o2 + 212);
  if (__builtin_object_size (h1->h2.e2, 0) != (s - o)) abort (); if (__builtin_object_size (h1->h2.e2, 1) != (s - o)) abort (); if (__builtin_object_size (h1->h2.e2, 2) != (s - o)) abort (); if (__builtin_object_size (h1->h2.e2, 3) != (s - o)) abort (); if (__builtin_object_size (&h1->h2.e2[0], 0) != (s - o)) abort (); if (__builtin_object_size (&h1->h2.e2[0], 1) != (s - o)) abort (); if (__builtin_object_size (&h1->h2.e2[0], 2) != (s - o)) abort (); if (__builtin_object_size (&h1->h2.e2[0], 3) != (s - o)) abort (); if (__builtin_object_size (&h1->h2.e2[1], 0) != ((s - o) - 1)) abort (); if (__builtin_object_size (&h1->h2.e2[1], 1) != ((s - o) - 1)) abort (); if (__builtin_object_size (&h1->h2.e2[1], 2) != ((s - o) - 1)) abort (); if (__builtin_object_size (&h1->h2.e2[1], 3) != ((s - o) - 1)) abort ();
  s = o2 + 212;
  if (__builtin_object_size (h2->h2.e2, 0) != (s - o)) abort (); if (__builtin_object_size (h2->h2.e2, 1) != (s - o)) abort (); if (__builtin_object_size (h2->h2.e2, 2) != (s - o)) abort (); if (__builtin_object_size (h2->h2.e2, 3) != (s - o)) abort (); if (__builtin_object_size (&h2->h2.e2[0], 0) != (s - o)) abort (); if (__builtin_object_size (&h2->h2.e2[0], 1) != (s - o)) abort (); if (__builtin_object_size (&h2->h2.e2[0], 2) != (s - o)) abort (); if (__builtin_object_size (&h2->h2.e2[0], 3) != (s - o)) abort (); if (__builtin_object_size (&h2->h2.e2[1], 0) != ((s - o) - 1)) abort (); if (__builtin_object_size (&h2->h2.e2[1], 1) != ((s - o) - 1)) abort (); if (__builtin_object_size (&h2->h2.e2[1], 2) != ((s - o) - 1)) abort (); if (__builtin_object_size (&h2->h2.e2[1], 3) != ((s - o) - 1)) abort ();
  free (h2);
  free (h1);

  return 0;
}
