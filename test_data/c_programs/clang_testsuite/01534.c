int a __attribute__((nodebug));
void b(int p __attribute__((nodebug))) {
  int b __attribute__((nodebug));
}
void t1() __attribute__((nodebug));
void t2() __attribute__((nodebug(2)));
