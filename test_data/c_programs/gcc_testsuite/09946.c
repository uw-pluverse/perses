






extern void abort (void);

extern int fails;








struct epoll_event_orig {
  unsigned int events;
  unsigned long long data;
};



struct epoll_event_structmax {
  unsigned int events;
  unsigned long long data;
} __attribute__ ((aligned));



struct epoll_event_struct4 {
  unsigned int events;
  unsigned long long data;
} __attribute__ ((aligned(4)));


struct epoll_event_struct8 {
  unsigned int events;
  unsigned long long data;
} __attribute__ ((aligned(8)));


struct epoll_event_data4 {
  unsigned int events;
  unsigned long long data __attribute__ ((aligned(4)));
};


struct epoll_event_data8 {
  unsigned int events;
  unsigned long long data __attribute__ ((aligned(8)));
};


struct epoll_event_p {
  unsigned int events;
  unsigned long long data;
} __attribute__ ((packed));


struct epoll_event_pstruct4 {
  unsigned int events;
  unsigned long long data;
} __attribute__ ((packed)) __attribute__ ((aligned(4)));


struct epoll_event_pstruct8 {
  unsigned int events;
  unsigned long long data;
} __attribute__ ((packed)) __attribute__ ((aligned(8)));


struct epoll_event_pdata4 {
  unsigned int events;
  unsigned long long data __attribute__ ((aligned(4)));
} __attribute__ ((packed));


struct epoll_event_pdata8 {
  unsigned int events;
  unsigned long long data __attribute__ ((aligned(8)));
} __attribute__ ((packed));
struct outer_orig { int i; struct epoll_event_orig ee; }; unsigned int v1_orig = 101; unsigned int v2_orig = 102; unsigned long long v3_orig = 0x0101010101010101ULL; struct outer_orig s_orig[2] = { {101, { 102, 0x0101010101010101ULL } }, { 101, { 102, 0x0101010101010101ULL } } }; extern void test_orig (void); extern void checkp_orig (struct outer_orig *); extern void checkg_orig (void); void pass_orig (struct outer_orig s) { checkp_orig (&s); } struct outer_orig return_orig (void) { return s_orig[0]; }

struct outer_structmax { int i; struct epoll_event_structmax ee; }; unsigned int v1_structmax = 103; unsigned int v2_structmax = 104; unsigned long long v3_structmax = 0x1212121212121212ULL; struct outer_structmax s_structmax[2] = { {103, { 104, 0x1212121212121212ULL } }, { 103, { 104, 0x1212121212121212ULL } } }; extern void test_structmax (void); extern void checkp_structmax (struct outer_structmax *); extern void checkg_structmax (void); void pass_structmax (struct outer_structmax s) { checkp_structmax (&s); } struct outer_structmax return_structmax (void) { return s_structmax[0]; }
struct outer_struct4 { int i; struct epoll_event_struct4 ee; }; unsigned int v1_struct4 = 105; unsigned int v2_struct4 = 106; unsigned long long v3_struct4 = 0x2323232323232323ULL; struct outer_struct4 s_struct4[2] = { {105, { 106, 0x2323232323232323ULL } }, { 105, { 106, 0x2323232323232323ULL } } }; extern void test_struct4 (void); extern void checkp_struct4 (struct outer_struct4 *); extern void checkg_struct4 (void); void pass_struct4 (struct outer_struct4 s) { checkp_struct4 (&s); } struct outer_struct4 return_struct4 (void) { return s_struct4[0]; }
struct outer_struct8 { int i; struct epoll_event_struct8 ee; }; unsigned int v1_struct8 = 107; unsigned int v2_struct8 = 108; unsigned long long v3_struct8 = 0x3434343434343434ULL; struct outer_struct8 s_struct8[2] = { {107, { 108, 0x3434343434343434ULL } }, { 107, { 108, 0x3434343434343434ULL } } }; extern void test_struct8 (void); extern void checkp_struct8 (struct outer_struct8 *); extern void checkg_struct8 (void); void pass_struct8 (struct outer_struct8 s) { checkp_struct8 (&s); } struct outer_struct8 return_struct8 (void) { return s_struct8[0]; }
struct outer_data4 { int i; struct epoll_event_data4 ee; }; unsigned int v1_data4 = 109; unsigned int v2_data4 = 110; unsigned long long v3_data4 = 0x4545454545454545ULL; struct outer_data4 s_data4[2] = { {109, { 110, 0x4545454545454545ULL } }, { 109, { 110, 0x4545454545454545ULL } } }; extern void test_data4 (void); extern void checkp_data4 (struct outer_data4 *); extern void checkg_data4 (void); void pass_data4 (struct outer_data4 s) { checkp_data4 (&s); } struct outer_data4 return_data4 (void) { return s_data4[0]; }
struct outer_data8 { int i; struct epoll_event_data8 ee; }; unsigned int v1_data8 = 111; unsigned int v2_data8 = 112; unsigned long long v3_data8 = 0x5656565656565656ULL; struct outer_data8 s_data8[2] = { {111, { 112, 0x5656565656565656ULL } }, { 111, { 112, 0x5656565656565656ULL } } }; extern void test_data8 (void); extern void checkp_data8 (struct outer_data8 *); extern void checkg_data8 (void); void pass_data8 (struct outer_data8 s) { checkp_data8 (&s); } struct outer_data8 return_data8 (void) { return s_data8[0]; }
struct outer_p { int i; struct epoll_event_p ee; }; unsigned int v1_p = 113; unsigned int v2_p = 114; unsigned long long v3_p = 0x6767676767676767ULL; struct outer_p s_p[2] = { {113, { 114, 0x6767676767676767ULL } }, { 113, { 114, 0x6767676767676767ULL } } }; extern void test_p (void); extern void checkp_p (struct outer_p *); extern void checkg_p (void); void pass_p (struct outer_p s) { checkp_p (&s); } struct outer_p return_p (void) { return s_p[0]; }
struct outer_pstruct4 { int i; struct epoll_event_pstruct4 ee; }; unsigned int v1_pstruct4 = 115; unsigned int v2_pstruct4 = 116; unsigned long long v3_pstruct4 = 0x7878787878787878ULL; struct outer_pstruct4 s_pstruct4[2] = { {115, { 116, 0x7878787878787878ULL } }, { 115, { 116, 0x7878787878787878ULL } } }; extern void test_pstruct4 (void); extern void checkp_pstruct4 (struct outer_pstruct4 *); extern void checkg_pstruct4 (void); void pass_pstruct4 (struct outer_pstruct4 s) { checkp_pstruct4 (&s); } struct outer_pstruct4 return_pstruct4 (void) { return s_pstruct4[0]; }
struct outer_pstruct8 { int i; struct epoll_event_pstruct8 ee; }; unsigned int v1_pstruct8 = 117; unsigned int v2_pstruct8 = 118; unsigned long long v3_pstruct8 = 0x8989898989898989ULL; struct outer_pstruct8 s_pstruct8[2] = { {117, { 118, 0x8989898989898989ULL } }, { 117, { 118, 0x8989898989898989ULL } } }; extern void test_pstruct8 (void); extern void checkp_pstruct8 (struct outer_pstruct8 *); extern void checkg_pstruct8 (void); void pass_pstruct8 (struct outer_pstruct8 s) { checkp_pstruct8 (&s); } struct outer_pstruct8 return_pstruct8 (void) { return s_pstruct8[0]; }
struct outer_pdata4 { int i; struct epoll_event_pdata4 ee; }; unsigned int v1_pdata4 = 119; unsigned int v2_pdata4 = 120; unsigned long long v3_pdata4 = 0x9A9A9A9A9A9A9A9AULL; struct outer_pdata4 s_pdata4[2] = { {119, { 120, 0x9A9A9A9A9A9A9A9AULL } }, { 119, { 120, 0x9A9A9A9A9A9A9A9AULL } } }; extern void test_pdata4 (void); extern void checkp_pdata4 (struct outer_pdata4 *); extern void checkg_pdata4 (void); void pass_pdata4 (struct outer_pdata4 s) { checkp_pdata4 (&s); } struct outer_pdata4 return_pdata4 (void) { return s_pdata4[0]; }
struct outer_pdata8 { int i; struct epoll_event_pdata8 ee; }; unsigned int v1_pdata8 = 121; unsigned int v2_pdata8 = 122; unsigned long long v3_pdata8 = 0xABABABABABABABABULL; struct outer_pdata8 s_pdata8[2] = { {121, { 122, 0xABABABABABABABABULL } }, { 121, { 122, 0xABABABABABABABABULL } } }; extern void test_pdata8 (void); extern void checkp_pdata8 (struct outer_pdata8 *); extern void checkg_pdata8 (void); void pass_pdata8 (struct outer_pdata8 s) { checkp_pdata8 (&s); } struct outer_pdata8 return_pdata8 (void) { return s_pdata8[0]; }


void
struct_align_2_x (void)
{


  test_orig();

  test_structmax();
  test_struct4();
  test_struct8();
  test_data4();
  test_data8();
  test_p();
  test_pstruct4();
  test_pstruct8();
  test_pdata4();
  test_pdata8();




  if (fails != 0)
    abort ();
}
