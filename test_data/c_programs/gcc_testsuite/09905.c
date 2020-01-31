typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void abort (void);

extern int fails;



typedef union { char c; short s; } Ucs;
typedef union { char c; int i; } Uci;
typedef union { char c; long l; } Ucl;
typedef union { char c; long long ll; } Ucll;

typedef union { short s; int i; } Usi;
typedef union { short s; long l; } Usl;
typedef union { short s; long long ll; } Usll;

typedef union { int i; long l; } Uil;
typedef union { int i; long long ll; } Uill;

typedef union { long l; long long ll; } Ulll;






void initUcs (Ucs *p, int i) { p->c = (char)i; }
void initUci (Uci *p, int i) { p->c = (char)i; }
void initUcl (Ucl *p, int i) { p->c = (char)i; }
void initUcll (Ucll *p, int i) { p->c = (char)i; }






void initUsi (Usi *p, int i) { p->s = (short)i; }
void initUsl (Usl *p, int i) { p->s = (short)i; }
void initUsll (Usll *p, int i) { p->s = (short)i; }






void initUil (Uil *p, int i) { p->i = i; }
void initUill (Uill *p, int i) { p->i = i; }






void initUlll (Ulll *p, int i) { p->l = (long)i; }
extern Ucs g01Ucs, g02Ucs, g03Ucs, g04Ucs; extern Ucs g05Ucs, g06Ucs, g07Ucs, g08Ucs; extern Ucs g09Ucs, g10Ucs, g11Ucs, g12Ucs; extern Ucs g13Ucs, g14Ucs, g15Ucs, g16Ucs; extern void checkUcs (Ucs x, int i); void checkgUcs (void) { checkUcs (g01Ucs, 1); checkUcs (g02Ucs, 2); checkUcs (g03Ucs, 3); checkUcs (g04Ucs, 4); checkUcs (g05Ucs, 5); checkUcs (g06Ucs, 6); checkUcs (g07Ucs, 7); checkUcs (g08Ucs, 8); checkUcs (g09Ucs, 9); checkUcs (g10Ucs, 10); checkUcs (g11Ucs, 11); checkUcs (g12Ucs, 12); checkUcs (g13Ucs, 13); checkUcs (g14Ucs, 14); checkUcs (g15Ucs, 15); checkUcs (g16Ucs, 16); } Ucs test0Ucs (void) { return g01Ucs; } Ucs test1Ucs (Ucs x01) { return x01; } Ucs testvaUcs (int n, ...) { int i; Ucs rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Ucs); __builtin_va_end(ap); return rslt; }
extern Uci g01Uci, g02Uci, g03Uci, g04Uci; extern Uci g05Uci, g06Uci, g07Uci, g08Uci; extern Uci g09Uci, g10Uci, g11Uci, g12Uci; extern Uci g13Uci, g14Uci, g15Uci, g16Uci; extern void checkUci (Uci x, int i); void checkgUci (void) { checkUci (g01Uci, 1); checkUci (g02Uci, 2); checkUci (g03Uci, 3); checkUci (g04Uci, 4); checkUci (g05Uci, 5); checkUci (g06Uci, 6); checkUci (g07Uci, 7); checkUci (g08Uci, 8); checkUci (g09Uci, 9); checkUci (g10Uci, 10); checkUci (g11Uci, 11); checkUci (g12Uci, 12); checkUci (g13Uci, 13); checkUci (g14Uci, 14); checkUci (g15Uci, 15); checkUci (g16Uci, 16); } Uci test0Uci (void) { return g01Uci; } Uci test1Uci (Uci x01) { return x01; } Uci testvaUci (int n, ...) { int i; Uci rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Uci); __builtin_va_end(ap); return rslt; }
extern Ucl g01Ucl, g02Ucl, g03Ucl, g04Ucl; extern Ucl g05Ucl, g06Ucl, g07Ucl, g08Ucl; extern Ucl g09Ucl, g10Ucl, g11Ucl, g12Ucl; extern Ucl g13Ucl, g14Ucl, g15Ucl, g16Ucl; extern void checkUcl (Ucl x, int i); void checkgUcl (void) { checkUcl (g01Ucl, 1); checkUcl (g02Ucl, 2); checkUcl (g03Ucl, 3); checkUcl (g04Ucl, 4); checkUcl (g05Ucl, 5); checkUcl (g06Ucl, 6); checkUcl (g07Ucl, 7); checkUcl (g08Ucl, 8); checkUcl (g09Ucl, 9); checkUcl (g10Ucl, 10); checkUcl (g11Ucl, 11); checkUcl (g12Ucl, 12); checkUcl (g13Ucl, 13); checkUcl (g14Ucl, 14); checkUcl (g15Ucl, 15); checkUcl (g16Ucl, 16); } Ucl test0Ucl (void) { return g01Ucl; } Ucl test1Ucl (Ucl x01) { return x01; } Ucl testvaUcl (int n, ...) { int i; Ucl rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Ucl); __builtin_va_end(ap); return rslt; }
extern Ucll g01Ucll, g02Ucll, g03Ucll, g04Ucll; extern Ucll g05Ucll, g06Ucll, g07Ucll, g08Ucll; extern Ucll g09Ucll, g10Ucll, g11Ucll, g12Ucll; extern Ucll g13Ucll, g14Ucll, g15Ucll, g16Ucll; extern void checkUcll (Ucll x, int i); void checkgUcll (void) { checkUcll (g01Ucll, 1); checkUcll (g02Ucll, 2); checkUcll (g03Ucll, 3); checkUcll (g04Ucll, 4); checkUcll (g05Ucll, 5); checkUcll (g06Ucll, 6); checkUcll (g07Ucll, 7); checkUcll (g08Ucll, 8); checkUcll (g09Ucll, 9); checkUcll (g10Ucll, 10); checkUcll (g11Ucll, 11); checkUcll (g12Ucll, 12); checkUcll (g13Ucll, 13); checkUcll (g14Ucll, 14); checkUcll (g15Ucll, 15); checkUcll (g16Ucll, 16); } Ucll test0Ucll (void) { return g01Ucll; } Ucll test1Ucll (Ucll x01) { return x01; } Ucll testvaUcll (int n, ...) { int i; Ucll rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Ucll); __builtin_va_end(ap); return rslt; }
extern Usi g01Usi, g02Usi, g03Usi, g04Usi; extern Usi g05Usi, g06Usi, g07Usi, g08Usi; extern Usi g09Usi, g10Usi, g11Usi, g12Usi; extern Usi g13Usi, g14Usi, g15Usi, g16Usi; extern void checkUsi (Usi x, int i); void checkgUsi (void) { checkUsi (g01Usi, 1); checkUsi (g02Usi, 2); checkUsi (g03Usi, 3); checkUsi (g04Usi, 4); checkUsi (g05Usi, 5); checkUsi (g06Usi, 6); checkUsi (g07Usi, 7); checkUsi (g08Usi, 8); checkUsi (g09Usi, 9); checkUsi (g10Usi, 10); checkUsi (g11Usi, 11); checkUsi (g12Usi, 12); checkUsi (g13Usi, 13); checkUsi (g14Usi, 14); checkUsi (g15Usi, 15); checkUsi (g16Usi, 16); } Usi test0Usi (void) { return g01Usi; } Usi test1Usi (Usi x01) { return x01; } Usi testvaUsi (int n, ...) { int i; Usi rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Usi); __builtin_va_end(ap); return rslt; }
extern Usl g01Usl, g02Usl, g03Usl, g04Usl; extern Usl g05Usl, g06Usl, g07Usl, g08Usl; extern Usl g09Usl, g10Usl, g11Usl, g12Usl; extern Usl g13Usl, g14Usl, g15Usl, g16Usl; extern void checkUsl (Usl x, int i); void checkgUsl (void) { checkUsl (g01Usl, 1); checkUsl (g02Usl, 2); checkUsl (g03Usl, 3); checkUsl (g04Usl, 4); checkUsl (g05Usl, 5); checkUsl (g06Usl, 6); checkUsl (g07Usl, 7); checkUsl (g08Usl, 8); checkUsl (g09Usl, 9); checkUsl (g10Usl, 10); checkUsl (g11Usl, 11); checkUsl (g12Usl, 12); checkUsl (g13Usl, 13); checkUsl (g14Usl, 14); checkUsl (g15Usl, 15); checkUsl (g16Usl, 16); } Usl test0Usl (void) { return g01Usl; } Usl test1Usl (Usl x01) { return x01; } Usl testvaUsl (int n, ...) { int i; Usl rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Usl); __builtin_va_end(ap); return rslt; }
extern Usll g01Usll, g02Usll, g03Usll, g04Usll; extern Usll g05Usll, g06Usll, g07Usll, g08Usll; extern Usll g09Usll, g10Usll, g11Usll, g12Usll; extern Usll g13Usll, g14Usll, g15Usll, g16Usll; extern void checkUsll (Usll x, int i); void checkgUsll (void) { checkUsll (g01Usll, 1); checkUsll (g02Usll, 2); checkUsll (g03Usll, 3); checkUsll (g04Usll, 4); checkUsll (g05Usll, 5); checkUsll (g06Usll, 6); checkUsll (g07Usll, 7); checkUsll (g08Usll, 8); checkUsll (g09Usll, 9); checkUsll (g10Usll, 10); checkUsll (g11Usll, 11); checkUsll (g12Usll, 12); checkUsll (g13Usll, 13); checkUsll (g14Usll, 14); checkUsll (g15Usll, 15); checkUsll (g16Usll, 16); } Usll test0Usll (void) { return g01Usll; } Usll test1Usll (Usll x01) { return x01; } Usll testvaUsll (int n, ...) { int i; Usll rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Usll); __builtin_va_end(ap); return rslt; }
extern Uil g01Uil, g02Uil, g03Uil, g04Uil; extern Uil g05Uil, g06Uil, g07Uil, g08Uil; extern Uil g09Uil, g10Uil, g11Uil, g12Uil; extern Uil g13Uil, g14Uil, g15Uil, g16Uil; extern void checkUil (Uil x, int i); void checkgUil (void) { checkUil (g01Uil, 1); checkUil (g02Uil, 2); checkUil (g03Uil, 3); checkUil (g04Uil, 4); checkUil (g05Uil, 5); checkUil (g06Uil, 6); checkUil (g07Uil, 7); checkUil (g08Uil, 8); checkUil (g09Uil, 9); checkUil (g10Uil, 10); checkUil (g11Uil, 11); checkUil (g12Uil, 12); checkUil (g13Uil, 13); checkUil (g14Uil, 14); checkUil (g15Uil, 15); checkUil (g16Uil, 16); } Uil test0Uil (void) { return g01Uil; } Uil test1Uil (Uil x01) { return x01; } Uil testvaUil (int n, ...) { int i; Uil rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Uil); __builtin_va_end(ap); return rslt; }
extern Uill g01Uill, g02Uill, g03Uill, g04Uill; extern Uill g05Uill, g06Uill, g07Uill, g08Uill; extern Uill g09Uill, g10Uill, g11Uill, g12Uill; extern Uill g13Uill, g14Uill, g15Uill, g16Uill; extern void checkUill (Uill x, int i); void checkgUill (void) { checkUill (g01Uill, 1); checkUill (g02Uill, 2); checkUill (g03Uill, 3); checkUill (g04Uill, 4); checkUill (g05Uill, 5); checkUill (g06Uill, 6); checkUill (g07Uill, 7); checkUill (g08Uill, 8); checkUill (g09Uill, 9); checkUill (g10Uill, 10); checkUill (g11Uill, 11); checkUill (g12Uill, 12); checkUill (g13Uill, 13); checkUill (g14Uill, 14); checkUill (g15Uill, 15); checkUill (g16Uill, 16); } Uill test0Uill (void) { return g01Uill; } Uill test1Uill (Uill x01) { return x01; } Uill testvaUill (int n, ...) { int i; Uill rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Uill); __builtin_va_end(ap); return rslt; }
extern Ulll g01Ulll, g02Ulll, g03Ulll, g04Ulll; extern Ulll g05Ulll, g06Ulll, g07Ulll, g08Ulll; extern Ulll g09Ulll, g10Ulll, g11Ulll, g12Ulll; extern Ulll g13Ulll, g14Ulll, g15Ulll, g16Ulll; extern void checkUlll (Ulll x, int i); void checkgUlll (void) { checkUlll (g01Ulll, 1); checkUlll (g02Ulll, 2); checkUlll (g03Ulll, 3); checkUlll (g04Ulll, 4); checkUlll (g05Ulll, 5); checkUlll (g06Ulll, 6); checkUlll (g07Ulll, 7); checkUlll (g08Ulll, 8); checkUlll (g09Ulll, 9); checkUlll (g10Ulll, 10); checkUlll (g11Ulll, 11); checkUlll (g12Ulll, 12); checkUlll (g13Ulll, 13); checkUlll (g14Ulll, 14); checkUlll (g15Ulll, 15); checkUlll (g16Ulll, 16); } Ulll test0Ulll (void) { return g01Ulll; } Ulll test1Ulll (Ulll x01) { return x01; } Ulll testvaUlll (int n, ...) { int i; Ulll rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Ulll); __builtin_va_end(ap); return rslt; }
