void nonvariadic1(int a, int b, int c);
void __attribute__((stdcall)) nonvariadic1(int a, int b, int c);
void nonvariadic2(int a, int b, int c);
void __attribute__((stdcall)) nonvariadic2(int a, int b, int c) { }
void variadic(int a, ...);
void __attribute__((stdcall)) variadic(int a, ...);
extern void (*a)(int, int);
__attribute__((cdecl)) extern void (*a)(int, int);
extern void (*b)(int, ...);
__attribute__((cdecl)) extern void (*b)(int, ...);
extern void (*c)(int, int);
__attribute__((stdcall)) extern void (*c)(int, int);
extern void (*d)(int, ...);
__attribute__((stdcall)) extern void (*d)(int, ...);
