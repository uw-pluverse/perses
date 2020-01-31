typedef struct S S;
extern _Atomic(S*) e;
void a(S* b, void* c) {
  void (*fp)(int) = 0;
  b++;
  b += 1;
  c++;
  c += 1;
  c--;
  c -= 1;
  (void) c[1];
  b = 1+b;
  void (*d)(S*,void*) = a;
  d += 1;
  d++;
  d--;
  d -= 1;
  (void)(1 + d);
  e++;
}
