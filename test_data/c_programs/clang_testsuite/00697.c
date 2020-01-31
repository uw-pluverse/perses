__declspec(dllimport) extern int ExternGlobalDecl;
int use22() { return ExternGlobalDecl; }
__declspec(dllimport) int GlobalDecl;
int use27() { return GlobalDecl; }
__declspec(dllimport) extern int GlobalRedecl1;
__declspec(dllimport) extern int GlobalRedecl1;
int use33() { return GlobalRedecl1; }
__declspec(dllimport) int GlobalRedecl2;
__declspec(dllimport) int GlobalRedecl2;
int use38() { return GlobalRedecl2; }
__declspec(dllimport) extern int GlobalRedecl3;
                      extern int GlobalRedecl3;
int use45() { return GlobalRedecl3; }
__declspec(dllimport) extern int GlobalRedecl4;
int use51() { return GlobalRedecl4; }
                      int GlobalRedecl4;
__declspec(dllimport) extern int GlobalRedecl5;
int use57() { return GlobalRedecl5; }
                      extern int GlobalRedecl5;
__declspec(dllimport) int GlobalRedecl6;
int functionScope() {
  extern int GlobalRedecl6;
  return GlobalRedecl6;
}
__declspec(dllimport) void decl(void);
void (*use_decl)(void) = &decl;
__declspec(dllimport) inline void inlineFunc(void) {}
void use88() { inlineFunc(); }
__declspec(dllimport) __attribute__((noinline)) inline void noinline(void) {}
__declspec(dllimport) __attribute__((always_inline)) inline void alwaysInline(void) {}
void use99() { noinline(); }
void use100() { alwaysInline(); }
__declspec(dllimport) void redecl1(void);
__declspec(dllimport) void redecl1(void);
void use106() { redecl1(); }
__declspec(dllimport) void redecl2(void);
                      void redecl2(void);
void use113() { redecl2(); }
__declspec(dllimport) void redecl3(void);
                      void redecl3(void) {}
void use119() { redecl3(); }
__declspec(dllimport) void redecl4(void);
void use125() { redecl4(); }
                      void redecl4(void) {}
__declspec(dllimport) void redecl5(void);
void use131() { redecl5(); }
                      void redecl5(void);
