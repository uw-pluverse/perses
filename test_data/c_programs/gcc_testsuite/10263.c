typedef int vtype;

extern vtype wv1;
static vtype Wv1a __attribute__((weakref ("wv1")));
vtype *pv1a = &Wv1a;

extern vtype wv2;
static vtype Wv2a __attribute__((weakref ("wv2")));
vtype *pv2a = &wv2;

typedef void ftype(void);

extern ftype wf1;
static ftype Wf1a __attribute__((weakref ("wf1")));
ftype *pf1a = &Wf1a;

extern ftype wf2;
static ftype Wf2a __attribute__((weakref ("wf2")));
ftype *pf2a = &wf2;
