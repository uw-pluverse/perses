




static void f(void);
void g(void (*x) (void)){x();}
static inline void f(void){}
void h(){g(f);}
int main(){h();return 0;}
