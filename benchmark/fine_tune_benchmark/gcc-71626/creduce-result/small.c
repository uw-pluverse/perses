typedef long a;
typedef a c __attribute__((__vector_size__(sizeof(a))));
b() {}
c d() {
  c e = {b};
  return e;
}
main() {}
