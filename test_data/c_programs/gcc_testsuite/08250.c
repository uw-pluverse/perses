





static int n;

static inline int f1 (void);
inline int f1 (void) { return n; }

static int f2 (void);
inline int f2 (void) { return n; }

static inline int f3 (void);
int f3 (void) { return n; }

static int f4 (void);
int f4 (void) { return n; }
