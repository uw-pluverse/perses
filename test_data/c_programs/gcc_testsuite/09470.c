


typedef const double cd;
void f (const double (*)[]);
void g (void) { f ((cd (*)[]) 0); }
