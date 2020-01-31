






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
struct outer_orig { int i; struct epoll_event_orig ee; }; extern unsigned int v1_orig; extern unsigned int v2_orig; extern unsigned long long v3_orig; extern struct outer_orig s_orig[2]; extern void pass_orig (struct outer_orig); extern struct outer_orig return_orig (void); void checkp_orig (struct outer_orig *p) { if (p->i != v1_orig) abort ();; if (p->ee.events != v2_orig) abort ();; if (p->ee.data != v3_orig) abort ();; } void test_orig (void) { struct outer_orig s; ; ; ; checkp_orig (&s_orig[0]); checkp_orig (&s_orig[1]); ; ; pass_orig (s_orig[0]); ; ; s = return_orig (); checkp_orig (&s); ; }

struct outer_structmax { int i; struct epoll_event_structmax ee; }; extern unsigned int v1_structmax; extern unsigned int v2_structmax; extern unsigned long long v3_structmax; extern struct outer_structmax s_structmax[2]; extern void pass_structmax (struct outer_structmax); extern struct outer_structmax return_structmax (void); void checkp_structmax (struct outer_structmax *p) { if (p->i != v1_structmax) abort ();; if (p->ee.events != v2_structmax) abort ();; if (p->ee.data != v3_structmax) abort ();; } void test_structmax (void) { struct outer_structmax s; ; ; ; checkp_structmax (&s_structmax[0]); checkp_structmax (&s_structmax[1]); ; ; pass_structmax (s_structmax[0]); ; ; s = return_structmax (); checkp_structmax (&s); ; }
struct outer_struct4 { int i; struct epoll_event_struct4 ee; }; extern unsigned int v1_struct4; extern unsigned int v2_struct4; extern unsigned long long v3_struct4; extern struct outer_struct4 s_struct4[2]; extern void pass_struct4 (struct outer_struct4); extern struct outer_struct4 return_struct4 (void); void checkp_struct4 (struct outer_struct4 *p) { if (p->i != v1_struct4) abort ();; if (p->ee.events != v2_struct4) abort ();; if (p->ee.data != v3_struct4) abort ();; } void test_struct4 (void) { struct outer_struct4 s; ; ; ; checkp_struct4 (&s_struct4[0]); checkp_struct4 (&s_struct4[1]); ; ; pass_struct4 (s_struct4[0]); ; ; s = return_struct4 (); checkp_struct4 (&s); ; }
struct outer_struct8 { int i; struct epoll_event_struct8 ee; }; extern unsigned int v1_struct8; extern unsigned int v2_struct8; extern unsigned long long v3_struct8; extern struct outer_struct8 s_struct8[2]; extern void pass_struct8 (struct outer_struct8); extern struct outer_struct8 return_struct8 (void); void checkp_struct8 (struct outer_struct8 *p) { if (p->i != v1_struct8) abort ();; if (p->ee.events != v2_struct8) abort ();; if (p->ee.data != v3_struct8) abort ();; } void test_struct8 (void) { struct outer_struct8 s; ; ; ; checkp_struct8 (&s_struct8[0]); checkp_struct8 (&s_struct8[1]); ; ; pass_struct8 (s_struct8[0]); ; ; s = return_struct8 (); checkp_struct8 (&s); ; }
struct outer_data4 { int i; struct epoll_event_data4 ee; }; extern unsigned int v1_data4; extern unsigned int v2_data4; extern unsigned long long v3_data4; extern struct outer_data4 s_data4[2]; extern void pass_data4 (struct outer_data4); extern struct outer_data4 return_data4 (void); void checkp_data4 (struct outer_data4 *p) { if (p->i != v1_data4) abort ();; if (p->ee.events != v2_data4) abort ();; if (p->ee.data != v3_data4) abort ();; } void test_data4 (void) { struct outer_data4 s; ; ; ; checkp_data4 (&s_data4[0]); checkp_data4 (&s_data4[1]); ; ; pass_data4 (s_data4[0]); ; ; s = return_data4 (); checkp_data4 (&s); ; }
struct outer_data8 { int i; struct epoll_event_data8 ee; }; extern unsigned int v1_data8; extern unsigned int v2_data8; extern unsigned long long v3_data8; extern struct outer_data8 s_data8[2]; extern void pass_data8 (struct outer_data8); extern struct outer_data8 return_data8 (void); void checkp_data8 (struct outer_data8 *p) { if (p->i != v1_data8) abort ();; if (p->ee.events != v2_data8) abort ();; if (p->ee.data != v3_data8) abort ();; } void test_data8 (void) { struct outer_data8 s; ; ; ; checkp_data8 (&s_data8[0]); checkp_data8 (&s_data8[1]); ; ; pass_data8 (s_data8[0]); ; ; s = return_data8 (); checkp_data8 (&s); ; }
struct outer_p { int i; struct epoll_event_p ee; }; extern unsigned int v1_p; extern unsigned int v2_p; extern unsigned long long v3_p; extern struct outer_p s_p[2]; extern void pass_p (struct outer_p); extern struct outer_p return_p (void); void checkp_p (struct outer_p *p) { if (p->i != v1_p) abort ();; if (p->ee.events != v2_p) abort ();; if (p->ee.data != v3_p) abort ();; } void test_p (void) { struct outer_p s; ; ; ; checkp_p (&s_p[0]); checkp_p (&s_p[1]); ; ; pass_p (s_p[0]); ; ; s = return_p (); checkp_p (&s); ; }
struct outer_pstruct4 { int i; struct epoll_event_pstruct4 ee; }; extern unsigned int v1_pstruct4; extern unsigned int v2_pstruct4; extern unsigned long long v3_pstruct4; extern struct outer_pstruct4 s_pstruct4[2]; extern void pass_pstruct4 (struct outer_pstruct4); extern struct outer_pstruct4 return_pstruct4 (void); void checkp_pstruct4 (struct outer_pstruct4 *p) { if (p->i != v1_pstruct4) abort ();; if (p->ee.events != v2_pstruct4) abort ();; if (p->ee.data != v3_pstruct4) abort ();; } void test_pstruct4 (void) { struct outer_pstruct4 s; ; ; ; checkp_pstruct4 (&s_pstruct4[0]); checkp_pstruct4 (&s_pstruct4[1]); ; ; pass_pstruct4 (s_pstruct4[0]); ; ; s = return_pstruct4 (); checkp_pstruct4 (&s); ; }
struct outer_pstruct8 { int i; struct epoll_event_pstruct8 ee; }; extern unsigned int v1_pstruct8; extern unsigned int v2_pstruct8; extern unsigned long long v3_pstruct8; extern struct outer_pstruct8 s_pstruct8[2]; extern void pass_pstruct8 (struct outer_pstruct8); extern struct outer_pstruct8 return_pstruct8 (void); void checkp_pstruct8 (struct outer_pstruct8 *p) { if (p->i != v1_pstruct8) abort ();; if (p->ee.events != v2_pstruct8) abort ();; if (p->ee.data != v3_pstruct8) abort ();; } void test_pstruct8 (void) { struct outer_pstruct8 s; ; ; ; checkp_pstruct8 (&s_pstruct8[0]); checkp_pstruct8 (&s_pstruct8[1]); ; ; pass_pstruct8 (s_pstruct8[0]); ; ; s = return_pstruct8 (); checkp_pstruct8 (&s); ; }
struct outer_pdata4 { int i; struct epoll_event_pdata4 ee; }; extern unsigned int v1_pdata4; extern unsigned int v2_pdata4; extern unsigned long long v3_pdata4; extern struct outer_pdata4 s_pdata4[2]; extern void pass_pdata4 (struct outer_pdata4); extern struct outer_pdata4 return_pdata4 (void); void checkp_pdata4 (struct outer_pdata4 *p) { if (p->i != v1_pdata4) abort ();; if (p->ee.events != v2_pdata4) abort ();; if (p->ee.data != v3_pdata4) abort ();; } void test_pdata4 (void) { struct outer_pdata4 s; ; ; ; checkp_pdata4 (&s_pdata4[0]); checkp_pdata4 (&s_pdata4[1]); ; ; pass_pdata4 (s_pdata4[0]); ; ; s = return_pdata4 (); checkp_pdata4 (&s); ; }
struct outer_pdata8 { int i; struct epoll_event_pdata8 ee; }; extern unsigned int v1_pdata8; extern unsigned int v2_pdata8; extern unsigned long long v3_pdata8; extern struct outer_pdata8 s_pdata8[2]; extern void pass_pdata8 (struct outer_pdata8); extern struct outer_pdata8 return_pdata8 (void); void checkp_pdata8 (struct outer_pdata8 *p) { if (p->i != v1_pdata8) abort ();; if (p->ee.events != v2_pdata8) abort ();; if (p->ee.data != v3_pdata8) abort ();; } void test_pdata8 (void) { struct outer_pdata8 s; ; ; ; checkp_pdata8 (&s_pdata8[0]); checkp_pdata8 (&s_pdata8[1]); ; ; pass_pdata8 (s_pdata8[0]); ; ; s = return_pdata8 (); checkp_pdata8 (&s); ; }
