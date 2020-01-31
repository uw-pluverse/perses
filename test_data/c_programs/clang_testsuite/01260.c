void callee_0() {}
void callee_1() {}
void callee_2() {}
void callee_3() {}
void *CalleeAddrs[] = {callee_0, callee_1, callee_2, callee_3};
extern void lprofSetMaxValsPerSite(unsigned);
int CallSeqTwoTarget_1[] = {0, 0, 0, 0, 0, 1, 1};
int CallSeqTwoTarget_2[] = {1, 1, 0, 0, 0, 0, 0};
int CallSeqTwoTarget_3[] = {1, 0, 0, 1, 0, 0, 0};
int CallSeqTwoTarget_4[] = {0, 0, 0, 1, 0, 1, 0};
int CallSeqThreeTarget_1[] = {0, 0, 0, 0, 0, 0, 1, 2, 1};
int CallSeqThreeTarget_2[] = {1, 2, 1, 0, 0, 0, 0, 0, 0};
int CallSeqThreeTarget_3[] = {1, 0, 0, 2, 0, 0, 0, 1, 0};
int CallSeqThreeTarget_4[] = {0, 0, 0, 1, 0, 1, 0, 0, 2};
int CallSeqFourTarget_1[] = {1, 1, 1, 2, 2, 2, 2, 0, 0, 3, 0, 0, 3, 0, 0, 3,
                             0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3};
int CallSeqFourTarget_2[] = {0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0, 0, 3, 0,
                             0, 3, 0, 0, 3, 0, 0, 3, 1, 1, 1, 2, 2, 2, 2};
int CallSeqFourTarget_3[] = {0, 3, 0, 0, 1, 3, 0, 0, 0, 2, 0, 0, 3, 3, 0, 3,
                             2, 2, 0, 3, 3, 1, 0, 0, 1, 0, 0, 3, 0, 2, 0};
typedef void (*FPT)(void);
FPT getCalleeFunc(int I) { return CalleeAddrs[I]; }
int main() {
  int I;
  lprofSetMaxValsPerSite(1); for (I = 0; I < sizeof(CallSeqTwoTarget_1) / sizeof(*CallSeqTwoTarget_1); I++) { FPT FP = getCalleeFunc(CallSeqTwoTarget_1[I]); FP(); };
  lprofSetMaxValsPerSite(1); for (I = 0; I < sizeof(CallSeqTwoTarget_2) / sizeof(*CallSeqTwoTarget_2); I++) { FPT FP = getCalleeFunc(CallSeqTwoTarget_2[I]); FP(); };
  lprofSetMaxValsPerSite(1); for (I = 0; I < sizeof(CallSeqTwoTarget_3) / sizeof(*CallSeqTwoTarget_3); I++) { FPT FP = getCalleeFunc(CallSeqTwoTarget_3[I]); FP(); };
  lprofSetMaxValsPerSite(1); for (I = 0; I < sizeof(CallSeqTwoTarget_4) / sizeof(*CallSeqTwoTarget_4); I++) { FPT FP = getCalleeFunc(CallSeqTwoTarget_4[I]); FP(); };
  lprofSetMaxValsPerSite(1); for (I = 0; I < sizeof(CallSeqThreeTarget_1) / sizeof(*CallSeqThreeTarget_1); I++) { FPT FP = getCalleeFunc(CallSeqThreeTarget_1[I]); FP(); };
  lprofSetMaxValsPerSite(1); for (I = 0; I < sizeof(CallSeqThreeTarget_2) / sizeof(*CallSeqThreeTarget_2); I++) { FPT FP = getCalleeFunc(CallSeqThreeTarget_2[I]); FP(); };
  lprofSetMaxValsPerSite(1); for (I = 0; I < sizeof(CallSeqThreeTarget_3) / sizeof(*CallSeqThreeTarget_3); I++) { FPT FP = getCalleeFunc(CallSeqThreeTarget_3[I]); FP(); };
  lprofSetMaxValsPerSite(1); for (I = 0; I < sizeof(CallSeqThreeTarget_4) / sizeof(*CallSeqThreeTarget_4); I++) { FPT FP = getCalleeFunc(CallSeqThreeTarget_4[I]); FP(); };
  lprofSetMaxValsPerSite(2); for (I = 0; I < sizeof(CallSeqThreeTarget_1) / sizeof(*CallSeqThreeTarget_1); I++) { FPT FP = getCalleeFunc(CallSeqThreeTarget_1[I]); FP(); };
  lprofSetMaxValsPerSite(2); for (I = 0; I < sizeof(CallSeqThreeTarget_2) / sizeof(*CallSeqThreeTarget_2); I++) { FPT FP = getCalleeFunc(CallSeqThreeTarget_2[I]); FP(); };
  lprofSetMaxValsPerSite(2); for (I = 0; I < sizeof(CallSeqThreeTarget_3) / sizeof(*CallSeqThreeTarget_3); I++) { FPT FP = getCalleeFunc(CallSeqThreeTarget_3[I]); FP(); };
  lprofSetMaxValsPerSite(2); for (I = 0; I < sizeof(CallSeqThreeTarget_4) / sizeof(*CallSeqThreeTarget_4); I++) { FPT FP = getCalleeFunc(CallSeqThreeTarget_4[I]); FP(); };
  lprofSetMaxValsPerSite(1); for (I = 0; I < sizeof(CallSeqFourTarget_1) / sizeof(*CallSeqFourTarget_1); I++) { FPT FP = getCalleeFunc(CallSeqFourTarget_1[I]); FP(); };
  lprofSetMaxValsPerSite(1); for (I = 0; I < sizeof(CallSeqFourTarget_2) / sizeof(*CallSeqFourTarget_2); I++) { FPT FP = getCalleeFunc(CallSeqFourTarget_2[I]); FP(); };
  lprofSetMaxValsPerSite(1); for (I = 0; I < sizeof(CallSeqFourTarget_3) / sizeof(*CallSeqFourTarget_3); I++) { FPT FP = getCalleeFunc(CallSeqFourTarget_3[I]); FP(); };
  lprofSetMaxValsPerSite(2); for (I = 0; I < sizeof(CallSeqFourTarget_1) / sizeof(*CallSeqFourTarget_1); I++) { FPT FP = getCalleeFunc(CallSeqFourTarget_1[I]); FP(); };
  lprofSetMaxValsPerSite(2); for (I = 0; I < sizeof(CallSeqFourTarget_2) / sizeof(*CallSeqFourTarget_2); I++) { FPT FP = getCalleeFunc(CallSeqFourTarget_2[I]); FP(); };
  lprofSetMaxValsPerSite(2); for (I = 0; I < sizeof(CallSeqFourTarget_3) / sizeof(*CallSeqFourTarget_3); I++) { FPT FP = getCalleeFunc(CallSeqFourTarget_3[I]); FP(); };
  lprofSetMaxValsPerSite(3); for (I = 0; I < sizeof(CallSeqFourTarget_1) / sizeof(*CallSeqFourTarget_1); I++) { FPT FP = getCalleeFunc(CallSeqFourTarget_1[I]); FP(); };
  lprofSetMaxValsPerSite(3); for (I = 0; I < sizeof(CallSeqFourTarget_2) / sizeof(*CallSeqFourTarget_2); I++) { FPT FP = getCalleeFunc(CallSeqFourTarget_2[I]); FP(); };
  lprofSetMaxValsPerSite(3); for (I = 0; I < sizeof(CallSeqFourTarget_3) / sizeof(*CallSeqFourTarget_3); I++) { FPT FP = getCalleeFunc(CallSeqFourTarget_3[I]); FP(); };
  return 0;
}
