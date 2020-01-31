extern void f (__fp16);
extern void g (__fp16 *);
extern void (*pf) (__fp16);
extern void (*pg) (__fp16*);
typedef void(*tf) (__fp16);
typedef void(*tg) (__fp16*);
void kf(a)
 __fp16 a; {
}
void kg(a)
 __fp16 *a; {
}
extern __fp16 f1 (void);
extern __fp16 *g1 (void);
extern __fp16 (*pf1) (void);
extern __fp16 *(*gf1) (void);
typedef __fp16 (*tf1) (void);
typedef __fp16 *(*tg1) (void);
