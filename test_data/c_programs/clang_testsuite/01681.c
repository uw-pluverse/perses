struct test {
  signed char a;
};
char c;
struct test s;
int chk1[__alignof__(c) == 1 ? 1 : -1];
int chk2[__alignof__(s) == 1 ? 1 : -1];
