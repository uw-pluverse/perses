



extern void z();

void f() { if ( z ) z(); }
void g() { if ( z != 0 ) z(); }
void h() { if ( z != (void*)0 ) z(); }
