void f(void* arg);
void g() {
  __attribute__((cleanup(f))) void *g;
}
