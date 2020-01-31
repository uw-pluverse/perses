typedef int sigjmp_buf[((9 * 2) + 3 + 16) + 1];
int sigsetjmp(sigjmp_buf env, int savemask);
sigjmp_buf B;
int foo() {
  sigsetjmp(B, 1);
  bar();
}
