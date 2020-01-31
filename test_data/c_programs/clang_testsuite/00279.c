__declspec(thread) static void *c;
void f(void *p) {
  c = p;
}
