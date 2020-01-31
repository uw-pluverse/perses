



extern void z();
void *p;

void f() {
 if (z >= 0)
   z();
 if (0 >= z)
    z();
 if (p >= (void*)0)
    z();
 if ((void*)0 >= p)
    z();
 if (z >= (void*)0)
    z();
 if ((void*)0 >=z)
    z();
}
