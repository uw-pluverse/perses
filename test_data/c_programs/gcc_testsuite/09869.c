

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
char v1_orig = 49; double v2_orig = 1.0; int v3_orig = 111111; struct B1_orig b1_orig = { 49, 1.0 }; struct B2_orig b2_orig = { 49, { 1.0 } }; struct B3_orig b3_orig = { 49, { 1.0, 111111 } }; struct B1_orig ab1_orig[2] = { { 49, 1.0 }, { 49, 1.0 } }; struct B2_orig ab2_orig[2] = { { 49, { 1.0 } }, { 49, { 1.0 } } }; struct B3_orig ab3_orig[2] = { { 49, { 1.0, 111111 } }, { 49, { 1.0, 111111 } } }; extern void test_orig (void); extern void checkp1_orig (struct B1_orig *); extern void checkp2_orig (struct B2_orig *); extern void checkp3_orig (struct B3_orig *); extern void checkg1_orig (void); extern void checkg2_orig (void); extern void checkg3_orig (void); void pass1_orig (struct B1_orig s) { checkp1_orig (&s); } void pass2_orig (struct B2_orig s) { checkp2_orig (&s); } void pass3_orig (struct B3_orig s) { checkp3_orig (&s); } struct B1_orig return1_orig (void) { return ab1_orig[0]; } struct B2_orig return2_orig (void) { return ab2_orig[0]; } struct B3_orig return3_orig (void) { return ab3_orig[0]; }





char v1_p_all = 50; double v2_p_all = 2.0; int v3_p_all = 222222; struct B1_p_all b1_p_all = { 50, 2.0 }; struct B2_p_all b2_p_all = { 50, { 2.0 } }; struct B3_p_all b3_p_all = { 50, { 2.0, 222222 } }; struct B1_p_all ab1_p_all[2] = { { 50, 2.0 }, { 50, 2.0 } }; struct B2_p_all ab2_p_all[2] = { { 50, { 2.0 } }, { 50, { 2.0 } } }; struct B3_p_all ab3_p_all[2] = { { 50, { 2.0, 222222 } }, { 50, { 2.0, 222222 } } }; extern void test_p_all (void); extern void checkp1_p_all (struct B1_p_all *); extern void checkp2_p_all (struct B2_p_all *); extern void checkp3_p_all (struct B3_p_all *); extern void checkg1_p_all (void); extern void checkg2_p_all (void); extern void checkg3_p_all (void); void pass1_p_all (struct B1_p_all s) { checkp1_p_all (&s); } void pass2_p_all (struct B2_p_all s) { checkp2_p_all (&s); } void pass3_p_all (struct B3_p_all s) { checkp3_p_all (&s); } struct B1_p_all return1_p_all (void) { return ab1_p_all[0]; } struct B2_p_all return2_p_all (void) { return ab2_p_all[0]; } struct B3_p_all return3_p_all (void) { return ab3_p_all[0]; }
char v1_p_inner = 51; double v2_p_inner = 3.0; int v3_p_inner = 333333; struct B1_p_inner b1_p_inner = { 51, 3.0 }; struct B2_p_inner b2_p_inner = { 51, { 3.0 } }; struct B3_p_inner b3_p_inner = { 51, { 3.0, 333333 } }; struct B1_p_inner ab1_p_inner[2] = { { 51, 3.0 }, { 51, 3.0 } }; struct B2_p_inner ab2_p_inner[2] = { { 51, { 3.0 } }, { 51, { 3.0 } } }; struct B3_p_inner ab3_p_inner[2] = { { 51, { 3.0, 333333 } }, { 51, { 3.0, 333333 } } }; extern void test_p_inner (void); extern void checkp1_p_inner (struct B1_p_inner *); extern void checkp2_p_inner (struct B2_p_inner *); extern void checkp3_p_inner (struct B3_p_inner *); extern void checkg1_p_inner (void); extern void checkg2_p_inner (void); extern void checkg3_p_inner (void); void pass1_p_inner (struct B1_p_inner s) { checkp1_p_inner (&s); } void pass2_p_inner (struct B2_p_inner s) { checkp2_p_inner (&s); } void pass3_p_inner (struct B3_p_inner s) { checkp3_p_inner (&s); } struct B1_p_inner return1_p_inner (void) { return ab1_p_inner[0]; } struct B2_p_inner return2_p_inner (void) { return ab2_p_inner[0]; } struct B3_p_inner return3_p_inner (void) { return ab3_p_inner[0]; }
char v1_p_outer = 52; double v2_p_outer = 4.0; int v3_p_outer = 444444; struct B1_p_outer b1_p_outer = { 52, 4.0 }; struct B2_p_outer b2_p_outer = { 52, { 4.0 } }; struct B3_p_outer b3_p_outer = { 52, { 4.0, 444444 } }; struct B1_p_outer ab1_p_outer[2] = { { 52, 4.0 }, { 52, 4.0 } }; struct B2_p_outer ab2_p_outer[2] = { { 52, { 4.0 } }, { 52, { 4.0 } } }; struct B3_p_outer ab3_p_outer[2] = { { 52, { 4.0, 444444 } }, { 52, { 4.0, 444444 } } }; extern void test_p_outer (void); extern void checkp1_p_outer (struct B1_p_outer *); extern void checkp2_p_outer (struct B2_p_outer *); extern void checkp3_p_outer (struct B3_p_outer *); extern void checkg1_p_outer (void); extern void checkg2_p_outer (void); extern void checkg3_p_outer (void); void pass1_p_outer (struct B1_p_outer s) { checkp1_p_outer (&s); } void pass2_p_outer (struct B2_p_outer s) { checkp2_p_outer (&s); } void pass3_p_outer (struct B3_p_outer s) { checkp3_p_outer (&s); } struct B1_p_outer return1_p_outer (void) { return ab1_p_outer[0]; } struct B2_p_outer return2_p_outer (void) { return ab2_p_outer[0]; } struct B3_p_outer return3_p_outer (void) { return ab3_p_outer[0]; }
char v1_a_max = 53; double v2_a_max = 5.0; int v3_a_max = 555555; struct B1_a_max b1_a_max = { 53, 5.0 }; struct B2_a_max b2_a_max = { 53, { 5.0 } }; struct B3_a_max b3_a_max = { 53, { 5.0, 555555 } }; struct B1_a_max ab1_a_max[2] = { { 53, 5.0 }, { 53, 5.0 } }; struct B2_a_max ab2_a_max[2] = { { 53, { 5.0 } }, { 53, { 5.0 } } }; struct B3_a_max ab3_a_max[2] = { { 53, { 5.0, 555555 } }, { 53, { 5.0, 555555 } } }; extern void test_a_max (void); extern void checkp1_a_max (struct B1_a_max *); extern void checkp2_a_max (struct B2_a_max *); extern void checkp3_a_max (struct B3_a_max *); extern void checkg1_a_max (void); extern void checkg2_a_max (void); extern void checkg3_a_max (void); void pass1_a_max (struct B1_a_max s) { checkp1_a_max (&s); } void pass2_a_max (struct B2_a_max s) { checkp2_a_max (&s); } void pass3_a_max (struct B3_a_max s) { checkp3_a_max (&s); } struct B1_a_max return1_a_max (void) { return ab1_a_max[0]; } struct B2_a_max return2_a_max (void) { return ab2_a_max[0]; } struct B3_a_max return3_a_max (void) { return ab3_a_max[0]; }
char v1_m_outer_p_inner = 54; double v2_m_outer_p_inner = 6.0; int v3_m_outer_p_inner = 666666; struct B1_m_outer_p_inner b1_m_outer_p_inner = { 54, 6.0 }; struct B2_m_outer_p_inner b2_m_outer_p_inner = { 54, { 6.0 } }; struct B3_m_outer_p_inner b3_m_outer_p_inner = { 54, { 6.0, 666666 } }; struct B1_m_outer_p_inner ab1_m_outer_p_inner[2] = { { 54, 6.0 }, { 54, 6.0 } }; struct B2_m_outer_p_inner ab2_m_outer_p_inner[2] = { { 54, { 6.0 } }, { 54, { 6.0 } } }; struct B3_m_outer_p_inner ab3_m_outer_p_inner[2] = { { 54, { 6.0, 666666 } }, { 54, { 6.0, 666666 } } }; extern void test_m_outer_p_inner (void); extern void checkp1_m_outer_p_inner (struct B1_m_outer_p_inner *); extern void checkp2_m_outer_p_inner (struct B2_m_outer_p_inner *); extern void checkp3_m_outer_p_inner (struct B3_m_outer_p_inner *); extern void checkg1_m_outer_p_inner (void); extern void checkg2_m_outer_p_inner (void); extern void checkg3_m_outer_p_inner (void); void pass1_m_outer_p_inner (struct B1_m_outer_p_inner s) { checkp1_m_outer_p_inner (&s); } void pass2_m_outer_p_inner (struct B2_m_outer_p_inner s) { checkp2_m_outer_p_inner (&s); } void pass3_m_outer_p_inner (struct B3_m_outer_p_inner s) { checkp3_m_outer_p_inner (&s); } struct B1_m_outer_p_inner return1_m_outer_p_inner (void) { return ab1_m_outer_p_inner[0]; } struct B2_m_outer_p_inner return2_m_outer_p_inner (void) { return ab2_m_outer_p_inner[0]; } struct B3_m_outer_p_inner return3_m_outer_p_inner (void) { return ab3_m_outer_p_inner[0]; }
char v1_m_inner_p_outer = 55; double v2_m_inner_p_outer = 7.0; int v3_m_inner_p_outer = 777777; struct B1_m_inner_p_outer b1_m_inner_p_outer = { 55, 7.0 }; struct B2_m_inner_p_outer b2_m_inner_p_outer = { 55, { 7.0 } }; struct B3_m_inner_p_outer b3_m_inner_p_outer = { 55, { 7.0, 777777 } }; struct B1_m_inner_p_outer ab1_m_inner_p_outer[2] = { { 55, 7.0 }, { 55, 7.0 } }; struct B2_m_inner_p_outer ab2_m_inner_p_outer[2] = { { 55, { 7.0 } }, { 55, { 7.0 } } }; struct B3_m_inner_p_outer ab3_m_inner_p_outer[2] = { { 55, { 7.0, 777777 } }, { 55, { 7.0, 777777 } } }; extern void test_m_inner_p_outer (void); extern void checkp1_m_inner_p_outer (struct B1_m_inner_p_outer *); extern void checkp2_m_inner_p_outer (struct B2_m_inner_p_outer *); extern void checkp3_m_inner_p_outer (struct B3_m_inner_p_outer *); extern void checkg1_m_inner_p_outer (void); extern void checkg2_m_inner_p_outer (void); extern void checkg3_m_inner_p_outer (void); void pass1_m_inner_p_outer (struct B1_m_inner_p_outer s) { checkp1_m_inner_p_outer (&s); } void pass2_m_inner_p_outer (struct B2_m_inner_p_outer s) { checkp2_m_inner_p_outer (&s); } void pass3_m_inner_p_outer (struct B3_m_inner_p_outer s) { checkp3_m_inner_p_outer (&s); } struct B1_m_inner_p_outer return1_m_inner_p_outer (void) { return ab1_m_inner_p_outer[0]; } struct B2_m_inner_p_outer return2_m_inner_p_outer (void) { return ab2_m_inner_p_outer[0]; } struct B3_m_inner_p_outer return3_m_inner_p_outer (void) { return ab3_m_inner_p_outer[0]; }
void
struct_align_1_x (void)
{


  test_orig();

  test_p_all();
  test_p_inner();
  test_p_outer();
  test_a_max();
  test_m_outer_p_inner();
  test_m_inner_p_outer();




  if (fails != 0)
    abort ();
}
