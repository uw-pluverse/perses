




extern void v;
void f1 (void) { &v; }

extern void *pv;
void f2 (void) { &*pv; }

extern const void cv;
void f3 (void) { &cv; }

extern const void *pcv;
void f4 (void) { &*pcv; }
