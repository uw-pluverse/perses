extern int chroot(const char* path);
extern int chdir(const char* path);
void foo(void) {
}
void f1(void) {
  chroot("/usr/local");
  foo();
}
void f2(void) {
  chroot("/usr/local");
  chdir("/");
  foo();
}
void f3(void) {
  chroot("/usr/local");
  chdir("../");
  foo();
}
