

extern void abort (void);

extern int fails;





struct B1_orig {
  char c;
  double d;
};

struct A2_orig {
  double d;
};

struct B2_orig {
  char c;
  struct A2_orig a2;
};

struct A3_orig {
  double d;
  int i;
};

struct B3_orig {
  char c;
  struct A3_orig a3;
};



struct B1_p_all {
  char c;
  double d;
} __attribute__ ((packed));

struct A2_p_all {
  double d;
} __attribute__ ((packed));

struct B2_p_all {
  char c;
  struct A2_p_all a2;
} __attribute__ ((packed));

struct A3_p_all {
  double d;
  int i;
} __attribute__ ((packed));

struct B3_p_all {
  char c;
  struct A3_p_all a3;
} __attribute__ ((packed));


struct B1_p_inner {
  char c;
  double d;
};

struct A2_p_inner {
  double d;
} __attribute__ ((packed));

struct B2_p_inner {
  char c;
  struct A2_p_inner a2;
};

struct A3_p_inner {
  double d;
  int i;
} __attribute__ ((packed));

struct B3_p_inner {
  char c;
  struct A3_p_inner a3;
};


struct B1_p_outer {
  char c;
  double d;
} __attribute__ ((packed));

struct A2_p_outer {
  double d;
};

struct B2_p_outer {
  char c;
  struct A2_p_outer a2;
} __attribute__ ((packed));

struct A3_p_outer {
  double d;
  int i;
};

struct B3_p_outer {
  char c;
  struct A3_p_outer a3;
} __attribute__ ((packed));


struct B1_a_max {
  char c;
  double d;
} __attribute__ ((aligned));

struct A2_a_max {
  double d;
} __attribute__ ((aligned));

struct B2_a_max {
  char c;
  struct A2_a_max a2;
} __attribute__ ((aligned));

struct A3_a_max {
  double d;
  int i;
} __attribute__ ((aligned));

struct B3_a_max {
  char c;
  struct A3_a_max a3;
} __attribute__ ((aligned));


struct B1_m_outer_p_inner {
  char c;
  double d;
} __attribute__ ((aligned)) __attribute__ ((packed));

struct A2_m_outer_p_inner {
  double d;
} __attribute__ ((packed));

struct B2_m_outer_p_inner {
  char c;
  struct A2_m_outer_p_inner a2;
} __attribute__ ((aligned));

struct A3_m_outer_p_inner {
  double d;
  int i;
} __attribute__ ((packed));

struct B3_m_outer_p_inner {
  char c;
  struct A3_m_outer_p_inner a3;
} __attribute__ ((aligned));


struct B1_m_inner_p_outer {
  char c;
  double d;
} __attribute__ ((aligned)) __attribute__ ((packed));

struct A2_m_inner_p_outer {
  double d;
} __attribute__ ((aligned));

struct B2_m_inner_p_outer {
  char c;
  struct A2_m_inner_p_outer a2;
} __attribute__ ((packed));

struct A3_m_inner_p_outer {
  double d;
  int i;
} __attribute__ ((aligned));

struct B3_m_inner_p_outer {
  char c;
  struct A3_m_inner_p_outer a3;
} __attribute__ ((packed));
extern char v1_orig; extern double v2_orig; extern int v3_orig; extern struct B1_orig b1_orig, ab1_orig[2]; extern struct B2_orig b2_orig, ab2_orig[2]; extern struct B3_orig b3_orig, ab3_orig[2]; extern void pass1_orig (struct B1_orig); extern void pass2_orig (struct B2_orig); extern void pass3_orig (struct B3_orig); extern struct B1_orig return1_orig (void); extern struct B2_orig return2_orig (void); extern struct B3_orig return3_orig (void); void checkp1_orig (struct B1_orig *p) { if (p->c != v1_orig) abort ();; if (p->d != v2_orig) abort ();; } void checkp2_orig (struct B2_orig *p) { if (p->c != v1_orig) abort ();; if (p->a2.d != v2_orig) abort ();; } void checkp3_orig (struct B3_orig *p) { if (p->c != v1_orig) abort ();; if (p->a3.d != v2_orig) abort ();; if (p->a3.i != v3_orig) abort ();; } void test_orig (void) { struct B1_orig s1; struct B2_orig s2; struct B3_orig s3; ; ; ; checkp1_orig (&b1_orig); checkp2_orig (&b2_orig); checkp3_orig (&b3_orig); ; ; checkp1_orig (&ab1_orig[1]); checkp2_orig (&ab2_orig[1]); checkp3_orig (&ab3_orig[1]); ; ; pass1_orig (b1_orig); pass2_orig (b2_orig); pass3_orig (b3_orig); ; ; s1 = return1_orig (); checkp1_orig (&s1); s2 = return2_orig (); checkp2_orig (&s2); s3 = return3_orig (); checkp3_orig (&s3); ; }

extern char v1_p_all; extern double v2_p_all; extern int v3_p_all; extern struct B1_p_all b1_p_all, ab1_p_all[2]; extern struct B2_p_all b2_p_all, ab2_p_all[2]; extern struct B3_p_all b3_p_all, ab3_p_all[2]; extern void pass1_p_all (struct B1_p_all); extern void pass2_p_all (struct B2_p_all); extern void pass3_p_all (struct B3_p_all); extern struct B1_p_all return1_p_all (void); extern struct B2_p_all return2_p_all (void); extern struct B3_p_all return3_p_all (void); void checkp1_p_all (struct B1_p_all *p) { if (p->c != v1_p_all) abort ();; if (p->d != v2_p_all) abort ();; } void checkp2_p_all (struct B2_p_all *p) { if (p->c != v1_p_all) abort ();; if (p->a2.d != v2_p_all) abort ();; } void checkp3_p_all (struct B3_p_all *p) { if (p->c != v1_p_all) abort ();; if (p->a3.d != v2_p_all) abort ();; if (p->a3.i != v3_p_all) abort ();; } void test_p_all (void) { struct B1_p_all s1; struct B2_p_all s2; struct B3_p_all s3; ; ; ; checkp1_p_all (&b1_p_all); checkp2_p_all (&b2_p_all); checkp3_p_all (&b3_p_all); ; ; checkp1_p_all (&ab1_p_all[1]); checkp2_p_all (&ab2_p_all[1]); checkp3_p_all (&ab3_p_all[1]); ; ; pass1_p_all (b1_p_all); pass2_p_all (b2_p_all); pass3_p_all (b3_p_all); ; ; s1 = return1_p_all (); checkp1_p_all (&s1); s2 = return2_p_all (); checkp2_p_all (&s2); s3 = return3_p_all (); checkp3_p_all (&s3); ; }
extern char v1_p_inner; extern double v2_p_inner; extern int v3_p_inner; extern struct B1_p_inner b1_p_inner, ab1_p_inner[2]; extern struct B2_p_inner b2_p_inner, ab2_p_inner[2]; extern struct B3_p_inner b3_p_inner, ab3_p_inner[2]; extern void pass1_p_inner (struct B1_p_inner); extern void pass2_p_inner (struct B2_p_inner); extern void pass3_p_inner (struct B3_p_inner); extern struct B1_p_inner return1_p_inner (void); extern struct B2_p_inner return2_p_inner (void); extern struct B3_p_inner return3_p_inner (void); void checkp1_p_inner (struct B1_p_inner *p) { if (p->c != v1_p_inner) abort ();; if (p->d != v2_p_inner) abort ();; } void checkp2_p_inner (struct B2_p_inner *p) { if (p->c != v1_p_inner) abort ();; if (p->a2.d != v2_p_inner) abort ();; } void checkp3_p_inner (struct B3_p_inner *p) { if (p->c != v1_p_inner) abort ();; if (p->a3.d != v2_p_inner) abort ();; if (p->a3.i != v3_p_inner) abort ();; } void test_p_inner (void) { struct B1_p_inner s1; struct B2_p_inner s2; struct B3_p_inner s3; ; ; ; checkp1_p_inner (&b1_p_inner); checkp2_p_inner (&b2_p_inner); checkp3_p_inner (&b3_p_inner); ; ; checkp1_p_inner (&ab1_p_inner[1]); checkp2_p_inner (&ab2_p_inner[1]); checkp3_p_inner (&ab3_p_inner[1]); ; ; pass1_p_inner (b1_p_inner); pass2_p_inner (b2_p_inner); pass3_p_inner (b3_p_inner); ; ; s1 = return1_p_inner (); checkp1_p_inner (&s1); s2 = return2_p_inner (); checkp2_p_inner (&s2); s3 = return3_p_inner (); checkp3_p_inner (&s3); ; }
extern char v1_p_outer; extern double v2_p_outer; extern int v3_p_outer; extern struct B1_p_outer b1_p_outer, ab1_p_outer[2]; extern struct B2_p_outer b2_p_outer, ab2_p_outer[2]; extern struct B3_p_outer b3_p_outer, ab3_p_outer[2]; extern void pass1_p_outer (struct B1_p_outer); extern void pass2_p_outer (struct B2_p_outer); extern void pass3_p_outer (struct B3_p_outer); extern struct B1_p_outer return1_p_outer (void); extern struct B2_p_outer return2_p_outer (void); extern struct B3_p_outer return3_p_outer (void); void checkp1_p_outer (struct B1_p_outer *p) { if (p->c != v1_p_outer) abort ();; if (p->d != v2_p_outer) abort ();; } void checkp2_p_outer (struct B2_p_outer *p) { if (p->c != v1_p_outer) abort ();; if (p->a2.d != v2_p_outer) abort ();; } void checkp3_p_outer (struct B3_p_outer *p) { if (p->c != v1_p_outer) abort ();; if (p->a3.d != v2_p_outer) abort ();; if (p->a3.i != v3_p_outer) abort ();; } void test_p_outer (void) { struct B1_p_outer s1; struct B2_p_outer s2; struct B3_p_outer s3; ; ; ; checkp1_p_outer (&b1_p_outer); checkp2_p_outer (&b2_p_outer); checkp3_p_outer (&b3_p_outer); ; ; checkp1_p_outer (&ab1_p_outer[1]); checkp2_p_outer (&ab2_p_outer[1]); checkp3_p_outer (&ab3_p_outer[1]); ; ; pass1_p_outer (b1_p_outer); pass2_p_outer (b2_p_outer); pass3_p_outer (b3_p_outer); ; ; s1 = return1_p_outer (); checkp1_p_outer (&s1); s2 = return2_p_outer (); checkp2_p_outer (&s2); s3 = return3_p_outer (); checkp3_p_outer (&s3); ; }
extern char v1_a_max; extern double v2_a_max; extern int v3_a_max; extern struct B1_a_max b1_a_max, ab1_a_max[2]; extern struct B2_a_max b2_a_max, ab2_a_max[2]; extern struct B3_a_max b3_a_max, ab3_a_max[2]; extern void pass1_a_max (struct B1_a_max); extern void pass2_a_max (struct B2_a_max); extern void pass3_a_max (struct B3_a_max); extern struct B1_a_max return1_a_max (void); extern struct B2_a_max return2_a_max (void); extern struct B3_a_max return3_a_max (void); void checkp1_a_max (struct B1_a_max *p) { if (p->c != v1_a_max) abort ();; if (p->d != v2_a_max) abort ();; } void checkp2_a_max (struct B2_a_max *p) { if (p->c != v1_a_max) abort ();; if (p->a2.d != v2_a_max) abort ();; } void checkp3_a_max (struct B3_a_max *p) { if (p->c != v1_a_max) abort ();; if (p->a3.d != v2_a_max) abort ();; if (p->a3.i != v3_a_max) abort ();; } void test_a_max (void) { struct B1_a_max s1; struct B2_a_max s2; struct B3_a_max s3; ; ; ; checkp1_a_max (&b1_a_max); checkp2_a_max (&b2_a_max); checkp3_a_max (&b3_a_max); ; ; checkp1_a_max (&ab1_a_max[1]); checkp2_a_max (&ab2_a_max[1]); checkp3_a_max (&ab3_a_max[1]); ; ; pass1_a_max (b1_a_max); pass2_a_max (b2_a_max); pass3_a_max (b3_a_max); ; ; s1 = return1_a_max (); checkp1_a_max (&s1); s2 = return2_a_max (); checkp2_a_max (&s2); s3 = return3_a_max (); checkp3_a_max (&s3); ; }
extern char v1_m_outer_p_inner; extern double v2_m_outer_p_inner; extern int v3_m_outer_p_inner; extern struct B1_m_outer_p_inner b1_m_outer_p_inner, ab1_m_outer_p_inner[2]; extern struct B2_m_outer_p_inner b2_m_outer_p_inner, ab2_m_outer_p_inner[2]; extern struct B3_m_outer_p_inner b3_m_outer_p_inner, ab3_m_outer_p_inner[2]; extern void pass1_m_outer_p_inner (struct B1_m_outer_p_inner); extern void pass2_m_outer_p_inner (struct B2_m_outer_p_inner); extern void pass3_m_outer_p_inner (struct B3_m_outer_p_inner); extern struct B1_m_outer_p_inner return1_m_outer_p_inner (void); extern struct B2_m_outer_p_inner return2_m_outer_p_inner (void); extern struct B3_m_outer_p_inner return3_m_outer_p_inner (void); void checkp1_m_outer_p_inner (struct B1_m_outer_p_inner *p) { if (p->c != v1_m_outer_p_inner) abort ();; if (p->d != v2_m_outer_p_inner) abort ();; } void checkp2_m_outer_p_inner (struct B2_m_outer_p_inner *p) { if (p->c != v1_m_outer_p_inner) abort ();; if (p->a2.d != v2_m_outer_p_inner) abort ();; } void checkp3_m_outer_p_inner (struct B3_m_outer_p_inner *p) { if (p->c != v1_m_outer_p_inner) abort ();; if (p->a3.d != v2_m_outer_p_inner) abort ();; if (p->a3.i != v3_m_outer_p_inner) abort ();; } void test_m_outer_p_inner (void) { struct B1_m_outer_p_inner s1; struct B2_m_outer_p_inner s2; struct B3_m_outer_p_inner s3; ; ; ; checkp1_m_outer_p_inner (&b1_m_outer_p_inner); checkp2_m_outer_p_inner (&b2_m_outer_p_inner); checkp3_m_outer_p_inner (&b3_m_outer_p_inner); ; ; checkp1_m_outer_p_inner (&ab1_m_outer_p_inner[1]); checkp2_m_outer_p_inner (&ab2_m_outer_p_inner[1]); checkp3_m_outer_p_inner (&ab3_m_outer_p_inner[1]); ; ; pass1_m_outer_p_inner (b1_m_outer_p_inner); pass2_m_outer_p_inner (b2_m_outer_p_inner); pass3_m_outer_p_inner (b3_m_outer_p_inner); ; ; s1 = return1_m_outer_p_inner (); checkp1_m_outer_p_inner (&s1); s2 = return2_m_outer_p_inner (); checkp2_m_outer_p_inner (&s2); s3 = return3_m_outer_p_inner (); checkp3_m_outer_p_inner (&s3); ; }
extern char v1_m_inner_p_outer; extern double v2_m_inner_p_outer; extern int v3_m_inner_p_outer; extern struct B1_m_inner_p_outer b1_m_inner_p_outer, ab1_m_inner_p_outer[2]; extern struct B2_m_inner_p_outer b2_m_inner_p_outer, ab2_m_inner_p_outer[2]; extern struct B3_m_inner_p_outer b3_m_inner_p_outer, ab3_m_inner_p_outer[2]; extern void pass1_m_inner_p_outer (struct B1_m_inner_p_outer); extern void pass2_m_inner_p_outer (struct B2_m_inner_p_outer); extern void pass3_m_inner_p_outer (struct B3_m_inner_p_outer); extern struct B1_m_inner_p_outer return1_m_inner_p_outer (void); extern struct B2_m_inner_p_outer return2_m_inner_p_outer (void); extern struct B3_m_inner_p_outer return3_m_inner_p_outer (void); void checkp1_m_inner_p_outer (struct B1_m_inner_p_outer *p) { if (p->c != v1_m_inner_p_outer) abort ();; if (p->d != v2_m_inner_p_outer) abort ();; } void checkp2_m_inner_p_outer (struct B2_m_inner_p_outer *p) { if (p->c != v1_m_inner_p_outer) abort ();; if (p->a2.d != v2_m_inner_p_outer) abort ();; } void checkp3_m_inner_p_outer (struct B3_m_inner_p_outer *p) { if (p->c != v1_m_inner_p_outer) abort ();; if (p->a3.d != v2_m_inner_p_outer) abort ();; if (p->a3.i != v3_m_inner_p_outer) abort ();; } void test_m_inner_p_outer (void) { struct B1_m_inner_p_outer s1; struct B2_m_inner_p_outer s2; struct B3_m_inner_p_outer s3; ; ; ; checkp1_m_inner_p_outer (&b1_m_inner_p_outer); checkp2_m_inner_p_outer (&b2_m_inner_p_outer); checkp3_m_inner_p_outer (&b3_m_inner_p_outer); ; ; checkp1_m_inner_p_outer (&ab1_m_inner_p_outer[1]); checkp2_m_inner_p_outer (&ab2_m_inner_p_outer[1]); checkp3_m_inner_p_outer (&ab3_m_inner_p_outer[1]); ; ; pass1_m_inner_p_outer (b1_m_inner_p_outer); pass2_m_inner_p_outer (b2_m_inner_p_outer); pass3_m_inner_p_outer (b3_m_inner_p_outer); ; ; s1 = return1_m_inner_p_outer (); checkp1_m_inner_p_outer (&s1); s2 = return2_m_inner_p_outer (); checkp2_m_inner_p_outer (&s2); s3 = return3_m_inner_p_outer (); checkp3_m_inner_p_outer (&s3); ; }
