typedef long l;
t() {}
typedef l v __attribute__((__vector_size__(sizeof(l))));
v e() {
  l c = t;
  v v = {c};
  return v;
}
main() {}
