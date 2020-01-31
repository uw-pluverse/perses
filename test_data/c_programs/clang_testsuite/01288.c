int puts(const char *);
__thread int foo;
int main(void) {
  puts("Hello, World");
  foo = 0;
}
