extern inline int f(int a) {return a;}
int g(void) {return f(0);}
int f(int b) {return 1+b;}
int h(void) {return f(1);}
extern inline int f2(int a, int b) {return a+b;}
int g2(void) {return f2(0,1);}
static int f2(int a, int b) {return a*b;}
int h2(void) {return f2(1,2);}
