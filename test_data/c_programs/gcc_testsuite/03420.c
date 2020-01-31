


struct A { int i; };

void foo()
{
    ((struct A) { 0 }).i += 1;
}
