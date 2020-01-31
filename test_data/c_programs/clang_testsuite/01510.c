void failure() __attribute__((diagnose_if()));
void failure() __attribute__((diagnose_if(0)));
void failure() __attribute__((diagnose_if(0, "")));
void failure() __attribute__((diagnose_if(0, "", "error", 1)));
void failure() __attribute__((diagnose_if(0, 0, "error")));
void failure() __attribute__((diagnose_if(0, "", "invalid")));
void failure() __attribute__((diagnose_if(0, "", "ERROR")));
void failure(int a) __attribute__((diagnose_if(a, "", "")));
void failure() __attribute__((diagnose_if(a, "", "")));
int globalVar;
void never_constant() __attribute__((diagnose_if(globalVar, "", "error")));
void never_constant() __attribute__((diagnose_if(globalVar, "", "warning")));
int alwaysok(int q) __attribute__((diagnose_if(0, "", "error")));
int neverok(int q) __attribute__((diagnose_if(1, "oh no", "error")));
int alwayswarn(int q) __attribute__((diagnose_if(1, "oh no", "warning")));
int neverwarn(int q) __attribute__((diagnose_if(0, "", "warning")));
void runConstant() {
  int m;
  alwaysok(0);
  alwaysok(1);
  alwaysok(m);
  {
    int (*pok)(int) = alwaysok;
    pok = &alwaysok;
  }
  neverok(0);
  neverok(1);
  neverok(m);
  {
    int (*pok)(int) = neverok;
    pok = &neverok;
  }
  alwayswarn(0);
  alwayswarn(1);
  alwayswarn(m);
  {
    int (*pok)(int) = alwayswarn;
    pok = &alwayswarn;
  }
  neverwarn(0);
  neverwarn(1);
  neverwarn(m);
  {
    int (*pok)(int) = neverwarn;
    pok = &neverwarn;
  }
}
int abs(int q) __attribute__((diagnose_if(q >= 0, "redundant abs call", "error")));
void runVariable() {
  int m;
  abs(-1);
  abs(1);
  abs(m);
  int (*pabs)(int) = abs;
  pabs = &abs;
}
int ovl1(const char *n) __attribute__((overloadable)) __attribute__((diagnose_if(n, "oh no", "error")));
int ovl1(void *m) __attribute__((overloadable));
int ovl2(const char *n) __attribute__((overloadable)) __attribute__((diagnose_if(n, "oh no", "error")));
int ovl2(char *m) __attribute__((overloadable));
void overloadsYay() {
  ovl1((void *)0);
  ovl1("");
  ovl2((void *)0);
}
void errorWarnDiagnose1() __attribute__((diagnose_if(1, "oh no", "error")))
  __attribute__((diagnose_if(1, "nop", "warning")));
void errorWarnDiagnose2() __attribute__((diagnose_if(1, "oh no", "error")))
  __attribute__((diagnose_if(1, "nop", "error")));
void errorWarnDiagnose3() __attribute__((diagnose_if(1, "nop", "warning")))
  __attribute__((diagnose_if(1, "oh no", "error")));
void errorWarnDiagnoseArg1(int a) __attribute__((diagnose_if(a == 1, "oh no", "error")))
  __attribute__((diagnose_if(a == 1, "nop", "warning")));
void errorWarnDiagnoseArg2(int a) __attribute__((diagnose_if(a == 1, "oh no", "error")))
  __attribute__((diagnose_if(a == 1, "nop", "error")));
void errorWarnDiagnoseArg3(int a) __attribute__((diagnose_if(a == 1, "nop", "warning")))
  __attribute__((diagnose_if(a == 1, "oh no", "error")));
void runErrorWarnDiagnose() {
  errorWarnDiagnose1();
  errorWarnDiagnose2();
  errorWarnDiagnose3();
  errorWarnDiagnoseArg1(1);
  errorWarnDiagnoseArg2(1);
  errorWarnDiagnoseArg3(1);
}
void warnWarnDiagnose() __attribute__((diagnose_if(1, "oh no!", "warning"))) __attribute__((diagnose_if(1, "foo", "warning")));
void runWarnWarnDiagnose() {
  warnWarnDiagnose();
}
void declsStackErr1(int a) __attribute__((diagnose_if(a & 1, "decl1", "error")));
void declsStackErr1(int a) __attribute__((diagnose_if(a & 2, "decl2", "error")));
void declsStackErr2();
void declsStackErr2() __attribute__((diagnose_if(1, "complaint", "error")));
void declsStackErr3() __attribute__((diagnose_if(1, "complaint", "error")));
void declsStackErr3();
void runDeclsStackErr() {
  declsStackErr1(0);
  declsStackErr1(1);
  declsStackErr1(2);
  declsStackErr1(3);
  declsStackErr2();
  declsStackErr3();
}
void declsStackWarn1(int a) __attribute__((diagnose_if(a & 1, "decl1", "warning")));
void declsStackWarn1(int a) __attribute__((diagnose_if(a & 2, "decl2", "warning")));
void declsStackWarn2();
void declsStackWarn2() __attribute__((diagnose_if(1, "complaint", "warning")));
void declsStackWarn3() __attribute__((diagnose_if(1, "complaint", "warning")));
void declsStackWarn3();
void runDeclsStackWarn() {
  declsStackWarn1(0);
  declsStackWarn1(1);
  declsStackWarn1(2);
  declsStackWarn1(3);
  declsStackWarn2();
  declsStackWarn3();
}
void noMsg(int n) __attribute__((diagnose_if(n, "", "warning")));
void runNoMsg() {
  noMsg(1);
}
void alwaysWarnWithArg(int a) __attribute__((diagnose_if(1 || a, "alwaysWarn", "warning")));
void runAlwaysWarnWithArg(int a) {
  alwaysWarnWithArg(a);
}
       
inline int system_header_func(int x)
  __attribute__((diagnose_if(x == x, "system header warning", "warning")))
{
  return 0;
}
void test_system_header() {
  system_header_func(0);
}
