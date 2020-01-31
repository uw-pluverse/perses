





__attribute__((noinline))
char *Ident(char *x) {
  return x;
}

__attribute__((noinline))
char *Func1() {
  char local[1 << 12];
  return Ident(local);
}

__attribute__((noinline))
void Func2(char *x) {
  *x = 1;
}
int main(int argc, char **argv) {
  Func2(Func1());
  return 0;
}
