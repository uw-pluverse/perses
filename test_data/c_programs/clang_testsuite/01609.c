int __attribute__((ms_abi)) var1;
int __attribute__((sysv_abi)) var2;
void __attribute__((ms_abi, sysv_abi)) foo3(void);
void __attribute__((ms_abi)) foo4();
void __attribute__((sysv_abi)) foo4(void);
void bar(int i, int j) __attribute__((ms_abi, cdecl));
void bar2(int i, int j) __attribute__((sysv_abi, cdecl));
