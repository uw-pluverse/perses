__declspec(dllexport) extern int ExternGlobalDecl;
__declspec(dllexport) int GlobalDef;
__declspec(dllexport) int GlobalInit = 1;
__declspec(dllexport) extern int GlobalDeclInit;
int GlobalDeclInit = 1;
__declspec(dllexport) extern int GlobalRedecl1;
__declspec(dllexport) int GlobalRedecl1;
__declspec(dllexport) extern int GlobalRedecl2;
                             int GlobalRedecl2;
__declspec(dllexport) void def(void) {}
__declspec(dllexport) inline void inlineFunc(void) {}
__declspec(dllexport) inline void externInlineFunc(void) {}
extern void externInlineFunc(void);
__declspec(dllexport) void redecl1(void);
__declspec(dllexport) void redecl1(void) {}
__declspec(dllexport) void redecl2(void);
                      void redecl2(void) {}
__attribute__((dllimport, dllexport)) int PrecedenceGlobal1A;
__declspec(dllimport) __declspec(dllexport) int PrecedenceGlobal1B;
__attribute__((dllexport, dllimport)) int PrecedenceGlobal2A;
__declspec(dllexport) __declspec(dllimport) int PrecedenceGlobal2B;
__declspec(dllexport) extern int PrecedenceGlobalRedecl1;
__declspec(dllimport) int PrecedenceGlobalRedecl1 = 0;
__declspec(dllimport) extern int PrecedenceGlobalRedecl2;
__declspec(dllexport) int PrecedenceGlobalRedecl2;
__attribute__((dllexport)) extern int PrecedenceGlobalMixed1;
__declspec(dllimport) int PrecedenceGlobalMixed1 = 1;
__attribute__((dllimport)) extern int PrecedenceGlobalMixed2;
__declspec(dllexport) int PrecedenceGlobalMixed2;
void __attribute__((dllimport, dllexport)) precedence1A(void) {}
void __declspec(dllimport) __declspec(dllexport) precedence1B(void) {}
void __attribute__((dllexport, dllimport)) precedence2A(void) {}
void __declspec(dllexport) __declspec(dllimport) precedence2B(void) {}
void __declspec(dllimport) precedenceRedecl1(void);
void __declspec(dllexport) precedenceRedecl1(void) {}
void __declspec(dllexport) precedenceRedecl2(void);
void __declspec(dllimport) precedenceRedecl2(void) {}
