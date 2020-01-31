

struct big { int i[sizeof (int) >= 4 && sizeof (void *) >= 4 ? 0x4000 : 4]; };
struct big gb;
int foo (struct big b, int x) { return b.i[x]; }



int main (void) { return foo (gb, 0) + foo (gb, 1); }
