void callee_0() {}
void callee_1() {}
void callee_2() {}
void *CalleeAddrs[] = {callee_0, callee_1, callee_2, callee_2, callee_2};
extern void lprofSetMaxValsPerSite(unsigned);
extern void __llvm_profile_reset_counters();
typedef void (*FPT)(void);
FPT getCalleeFunc(int I) { return CalleeAddrs[I]; }
int main() {
  int I;
  lprofSetMaxValsPerSite(2);
  for (I = 0; I < 5; I++) {
    if (I == 2) {
      __llvm_profile_reset_counters();
    }
    FPT FP = getCalleeFunc(I);
    FP();
  }
}
