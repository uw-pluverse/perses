extern void abort (void);

extern int fails;




const int test_va = 1;


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






void checkUcs (Ucs p, int i) { if (p.c != (char)i) abort (); }
void checkUci (Uci p, int i) { if (p.c != (char)i) abort (); }
void checkUcl (Ucl p, int i) { if (p.c != (char)i) abort (); }
void checkUcll (Ucll p, int i) { if (p.c != (char)i) abort (); }






void checkUsi (Usi p, int i) { if (p.s != (short)i) abort (); }
void checkUsl (Usl p, int i) { if (p.s != (short)i) abort (); }
void checkUsll (Usll p, int i) { if (p.s != (short)i) abort (); }






void checkUil (Uil p, int i) { if (p.i != i) abort (); }
void checkUill (Uill p, int i) { if (p.i != i) abort (); }






void checkUlll (Ulll p, int i) { if (p.l != (long)i) abort (); }

Ucs g01Ucs, g02Ucs, g03Ucs, g04Ucs; Ucs g05Ucs, g06Ucs, g07Ucs, g08Ucs; Ucs g09Ucs, g10Ucs, g11Ucs, g12Ucs; Ucs g13Ucs, g14Ucs, g15Ucs, g16Ucs; extern void initUcs (Ucs *p, int i); extern void checkgUcs (void); extern Ucs test0Ucs (void); extern Ucs test1Ucs (Ucs); extern Ucs testvaUcs (int n, ...); void testitUcs (void) { Ucs rslt; ; ; initUcs (&g01Ucs, 1); initUcs (&g02Ucs, 2); initUcs (&g03Ucs, 3); initUcs (&g04Ucs, 4); initUcs (&g05Ucs, 5); initUcs (&g06Ucs, 6); initUcs (&g07Ucs, 7); initUcs (&g08Ucs, 8); initUcs (&g09Ucs, 9); initUcs (&g10Ucs, 10); initUcs (&g11Ucs, 11); initUcs (&g12Ucs, 12); initUcs (&g13Ucs, 13); initUcs (&g14Ucs, 14); initUcs (&g15Ucs, 15); initUcs (&g16Ucs, 16); checkgUcs (); ; ; ; rslt = test0Ucs (); checkUcs (rslt, 1); ; ; ; rslt = test1Ucs (g01Ucs); checkUcs (rslt, 1); if (test_va) { ; ; ; rslt = testvaUcs (1, g01Ucs); checkUcs (rslt, 1); rslt = testvaUcs (5, g01Ucs, g02Ucs, g03Ucs, g04Ucs, g05Ucs); checkUcs (rslt, 5); rslt = testvaUcs (9, g01Ucs, g02Ucs, g03Ucs, g04Ucs, g05Ucs, g06Ucs, g07Ucs, g08Ucs, g09Ucs); checkUcs (rslt, 9); rslt = testvaUcs (16, g01Ucs, g02Ucs, g03Ucs, g04Ucs, g05Ucs, g06Ucs, g07Ucs, g08Ucs, g09Ucs, g10Ucs, g11Ucs, g12Ucs, g13Ucs, g14Ucs, g15Ucs, g16Ucs); checkUcs (rslt, 16); } ; }
Uci g01Uci, g02Uci, g03Uci, g04Uci; Uci g05Uci, g06Uci, g07Uci, g08Uci; Uci g09Uci, g10Uci, g11Uci, g12Uci; Uci g13Uci, g14Uci, g15Uci, g16Uci; extern void initUci (Uci *p, int i); extern void checkgUci (void); extern Uci test0Uci (void); extern Uci test1Uci (Uci); extern Uci testvaUci (int n, ...); void testitUci (void) { Uci rslt; ; ; initUci (&g01Uci, 1); initUci (&g02Uci, 2); initUci (&g03Uci, 3); initUci (&g04Uci, 4); initUci (&g05Uci, 5); initUci (&g06Uci, 6); initUci (&g07Uci, 7); initUci (&g08Uci, 8); initUci (&g09Uci, 9); initUci (&g10Uci, 10); initUci (&g11Uci, 11); initUci (&g12Uci, 12); initUci (&g13Uci, 13); initUci (&g14Uci, 14); initUci (&g15Uci, 15); initUci (&g16Uci, 16); checkgUci (); ; ; ; rslt = test0Uci (); checkUci (rslt, 1); ; ; ; rslt = test1Uci (g01Uci); checkUci (rslt, 1); if (test_va) { ; ; ; rslt = testvaUci (1, g01Uci); checkUci (rslt, 1); rslt = testvaUci (5, g01Uci, g02Uci, g03Uci, g04Uci, g05Uci); checkUci (rslt, 5); rslt = testvaUci (9, g01Uci, g02Uci, g03Uci, g04Uci, g05Uci, g06Uci, g07Uci, g08Uci, g09Uci); checkUci (rslt, 9); rslt = testvaUci (16, g01Uci, g02Uci, g03Uci, g04Uci, g05Uci, g06Uci, g07Uci, g08Uci, g09Uci, g10Uci, g11Uci, g12Uci, g13Uci, g14Uci, g15Uci, g16Uci); checkUci (rslt, 16); } ; }
Ucl g01Ucl, g02Ucl, g03Ucl, g04Ucl; Ucl g05Ucl, g06Ucl, g07Ucl, g08Ucl; Ucl g09Ucl, g10Ucl, g11Ucl, g12Ucl; Ucl g13Ucl, g14Ucl, g15Ucl, g16Ucl; extern void initUcl (Ucl *p, int i); extern void checkgUcl (void); extern Ucl test0Ucl (void); extern Ucl test1Ucl (Ucl); extern Ucl testvaUcl (int n, ...); void testitUcl (void) { Ucl rslt; ; ; initUcl (&g01Ucl, 1); initUcl (&g02Ucl, 2); initUcl (&g03Ucl, 3); initUcl (&g04Ucl, 4); initUcl (&g05Ucl, 5); initUcl (&g06Ucl, 6); initUcl (&g07Ucl, 7); initUcl (&g08Ucl, 8); initUcl (&g09Ucl, 9); initUcl (&g10Ucl, 10); initUcl (&g11Ucl, 11); initUcl (&g12Ucl, 12); initUcl (&g13Ucl, 13); initUcl (&g14Ucl, 14); initUcl (&g15Ucl, 15); initUcl (&g16Ucl, 16); checkgUcl (); ; ; ; rslt = test0Ucl (); checkUcl (rslt, 1); ; ; ; rslt = test1Ucl (g01Ucl); checkUcl (rslt, 1); if (test_va) { ; ; ; rslt = testvaUcl (1, g01Ucl); checkUcl (rslt, 1); rslt = testvaUcl (5, g01Ucl, g02Ucl, g03Ucl, g04Ucl, g05Ucl); checkUcl (rslt, 5); rslt = testvaUcl (9, g01Ucl, g02Ucl, g03Ucl, g04Ucl, g05Ucl, g06Ucl, g07Ucl, g08Ucl, g09Ucl); checkUcl (rslt, 9); rslt = testvaUcl (16, g01Ucl, g02Ucl, g03Ucl, g04Ucl, g05Ucl, g06Ucl, g07Ucl, g08Ucl, g09Ucl, g10Ucl, g11Ucl, g12Ucl, g13Ucl, g14Ucl, g15Ucl, g16Ucl); checkUcl (rslt, 16); } ; }
Ucll g01Ucll, g02Ucll, g03Ucll, g04Ucll; Ucll g05Ucll, g06Ucll, g07Ucll, g08Ucll; Ucll g09Ucll, g10Ucll, g11Ucll, g12Ucll; Ucll g13Ucll, g14Ucll, g15Ucll, g16Ucll; extern void initUcll (Ucll *p, int i); extern void checkgUcll (void); extern Ucll test0Ucll (void); extern Ucll test1Ucll (Ucll); extern Ucll testvaUcll (int n, ...); void testitUcll (void) { Ucll rslt; ; ; initUcll (&g01Ucll, 1); initUcll (&g02Ucll, 2); initUcll (&g03Ucll, 3); initUcll (&g04Ucll, 4); initUcll (&g05Ucll, 5); initUcll (&g06Ucll, 6); initUcll (&g07Ucll, 7); initUcll (&g08Ucll, 8); initUcll (&g09Ucll, 9); initUcll (&g10Ucll, 10); initUcll (&g11Ucll, 11); initUcll (&g12Ucll, 12); initUcll (&g13Ucll, 13); initUcll (&g14Ucll, 14); initUcll (&g15Ucll, 15); initUcll (&g16Ucll, 16); checkgUcll (); ; ; ; rslt = test0Ucll (); checkUcll (rslt, 1); ; ; ; rslt = test1Ucll (g01Ucll); checkUcll (rslt, 1); if (test_va) { ; ; ; rslt = testvaUcll (1, g01Ucll); checkUcll (rslt, 1); rslt = testvaUcll (5, g01Ucll, g02Ucll, g03Ucll, g04Ucll, g05Ucll); checkUcll (rslt, 5); rslt = testvaUcll (9, g01Ucll, g02Ucll, g03Ucll, g04Ucll, g05Ucll, g06Ucll, g07Ucll, g08Ucll, g09Ucll); checkUcll (rslt, 9); rslt = testvaUcll (16, g01Ucll, g02Ucll, g03Ucll, g04Ucll, g05Ucll, g06Ucll, g07Ucll, g08Ucll, g09Ucll, g10Ucll, g11Ucll, g12Ucll, g13Ucll, g14Ucll, g15Ucll, g16Ucll); checkUcll (rslt, 16); } ; }
Usi g01Usi, g02Usi, g03Usi, g04Usi; Usi g05Usi, g06Usi, g07Usi, g08Usi; Usi g09Usi, g10Usi, g11Usi, g12Usi; Usi g13Usi, g14Usi, g15Usi, g16Usi; extern void initUsi (Usi *p, int i); extern void checkgUsi (void); extern Usi test0Usi (void); extern Usi test1Usi (Usi); extern Usi testvaUsi (int n, ...); void testitUsi (void) { Usi rslt; ; ; initUsi (&g01Usi, 1); initUsi (&g02Usi, 2); initUsi (&g03Usi, 3); initUsi (&g04Usi, 4); initUsi (&g05Usi, 5); initUsi (&g06Usi, 6); initUsi (&g07Usi, 7); initUsi (&g08Usi, 8); initUsi (&g09Usi, 9); initUsi (&g10Usi, 10); initUsi (&g11Usi, 11); initUsi (&g12Usi, 12); initUsi (&g13Usi, 13); initUsi (&g14Usi, 14); initUsi (&g15Usi, 15); initUsi (&g16Usi, 16); checkgUsi (); ; ; ; rslt = test0Usi (); checkUsi (rslt, 1); ; ; ; rslt = test1Usi (g01Usi); checkUsi (rslt, 1); if (test_va) { ; ; ; rslt = testvaUsi (1, g01Usi); checkUsi (rslt, 1); rslt = testvaUsi (5, g01Usi, g02Usi, g03Usi, g04Usi, g05Usi); checkUsi (rslt, 5); rslt = testvaUsi (9, g01Usi, g02Usi, g03Usi, g04Usi, g05Usi, g06Usi, g07Usi, g08Usi, g09Usi); checkUsi (rslt, 9); rslt = testvaUsi (16, g01Usi, g02Usi, g03Usi, g04Usi, g05Usi, g06Usi, g07Usi, g08Usi, g09Usi, g10Usi, g11Usi, g12Usi, g13Usi, g14Usi, g15Usi, g16Usi); checkUsi (rslt, 16); } ; }
Usl g01Usl, g02Usl, g03Usl, g04Usl; Usl g05Usl, g06Usl, g07Usl, g08Usl; Usl g09Usl, g10Usl, g11Usl, g12Usl; Usl g13Usl, g14Usl, g15Usl, g16Usl; extern void initUsl (Usl *p, int i); extern void checkgUsl (void); extern Usl test0Usl (void); extern Usl test1Usl (Usl); extern Usl testvaUsl (int n, ...); void testitUsl (void) { Usl rslt; ; ; initUsl (&g01Usl, 1); initUsl (&g02Usl, 2); initUsl (&g03Usl, 3); initUsl (&g04Usl, 4); initUsl (&g05Usl, 5); initUsl (&g06Usl, 6); initUsl (&g07Usl, 7); initUsl (&g08Usl, 8); initUsl (&g09Usl, 9); initUsl (&g10Usl, 10); initUsl (&g11Usl, 11); initUsl (&g12Usl, 12); initUsl (&g13Usl, 13); initUsl (&g14Usl, 14); initUsl (&g15Usl, 15); initUsl (&g16Usl, 16); checkgUsl (); ; ; ; rslt = test0Usl (); checkUsl (rslt, 1); ; ; ; rslt = test1Usl (g01Usl); checkUsl (rslt, 1); if (test_va) { ; ; ; rslt = testvaUsl (1, g01Usl); checkUsl (rslt, 1); rslt = testvaUsl (5, g01Usl, g02Usl, g03Usl, g04Usl, g05Usl); checkUsl (rslt, 5); rslt = testvaUsl (9, g01Usl, g02Usl, g03Usl, g04Usl, g05Usl, g06Usl, g07Usl, g08Usl, g09Usl); checkUsl (rslt, 9); rslt = testvaUsl (16, g01Usl, g02Usl, g03Usl, g04Usl, g05Usl, g06Usl, g07Usl, g08Usl, g09Usl, g10Usl, g11Usl, g12Usl, g13Usl, g14Usl, g15Usl, g16Usl); checkUsl (rslt, 16); } ; }
Usll g01Usll, g02Usll, g03Usll, g04Usll; Usll g05Usll, g06Usll, g07Usll, g08Usll; Usll g09Usll, g10Usll, g11Usll, g12Usll; Usll g13Usll, g14Usll, g15Usll, g16Usll; extern void initUsll (Usll *p, int i); extern void checkgUsll (void); extern Usll test0Usll (void); extern Usll test1Usll (Usll); extern Usll testvaUsll (int n, ...); void testitUsll (void) { Usll rslt; ; ; initUsll (&g01Usll, 1); initUsll (&g02Usll, 2); initUsll (&g03Usll, 3); initUsll (&g04Usll, 4); initUsll (&g05Usll, 5); initUsll (&g06Usll, 6); initUsll (&g07Usll, 7); initUsll (&g08Usll, 8); initUsll (&g09Usll, 9); initUsll (&g10Usll, 10); initUsll (&g11Usll, 11); initUsll (&g12Usll, 12); initUsll (&g13Usll, 13); initUsll (&g14Usll, 14); initUsll (&g15Usll, 15); initUsll (&g16Usll, 16); checkgUsll (); ; ; ; rslt = test0Usll (); checkUsll (rslt, 1); ; ; ; rslt = test1Usll (g01Usll); checkUsll (rslt, 1); if (test_va) { ; ; ; rslt = testvaUsll (1, g01Usll); checkUsll (rslt, 1); rslt = testvaUsll (5, g01Usll, g02Usll, g03Usll, g04Usll, g05Usll); checkUsll (rslt, 5); rslt = testvaUsll (9, g01Usll, g02Usll, g03Usll, g04Usll, g05Usll, g06Usll, g07Usll, g08Usll, g09Usll); checkUsll (rslt, 9); rslt = testvaUsll (16, g01Usll, g02Usll, g03Usll, g04Usll, g05Usll, g06Usll, g07Usll, g08Usll, g09Usll, g10Usll, g11Usll, g12Usll, g13Usll, g14Usll, g15Usll, g16Usll); checkUsll (rslt, 16); } ; }
Uil g01Uil, g02Uil, g03Uil, g04Uil; Uil g05Uil, g06Uil, g07Uil, g08Uil; Uil g09Uil, g10Uil, g11Uil, g12Uil; Uil g13Uil, g14Uil, g15Uil, g16Uil; extern void initUil (Uil *p, int i); extern void checkgUil (void); extern Uil test0Uil (void); extern Uil test1Uil (Uil); extern Uil testvaUil (int n, ...); void testitUil (void) { Uil rslt; ; ; initUil (&g01Uil, 1); initUil (&g02Uil, 2); initUil (&g03Uil, 3); initUil (&g04Uil, 4); initUil (&g05Uil, 5); initUil (&g06Uil, 6); initUil (&g07Uil, 7); initUil (&g08Uil, 8); initUil (&g09Uil, 9); initUil (&g10Uil, 10); initUil (&g11Uil, 11); initUil (&g12Uil, 12); initUil (&g13Uil, 13); initUil (&g14Uil, 14); initUil (&g15Uil, 15); initUil (&g16Uil, 16); checkgUil (); ; ; ; rslt = test0Uil (); checkUil (rslt, 1); ; ; ; rslt = test1Uil (g01Uil); checkUil (rslt, 1); if (test_va) { ; ; ; rslt = testvaUil (1, g01Uil); checkUil (rslt, 1); rslt = testvaUil (5, g01Uil, g02Uil, g03Uil, g04Uil, g05Uil); checkUil (rslt, 5); rslt = testvaUil (9, g01Uil, g02Uil, g03Uil, g04Uil, g05Uil, g06Uil, g07Uil, g08Uil, g09Uil); checkUil (rslt, 9); rslt = testvaUil (16, g01Uil, g02Uil, g03Uil, g04Uil, g05Uil, g06Uil, g07Uil, g08Uil, g09Uil, g10Uil, g11Uil, g12Uil, g13Uil, g14Uil, g15Uil, g16Uil); checkUil (rslt, 16); } ; }
Uill g01Uill, g02Uill, g03Uill, g04Uill; Uill g05Uill, g06Uill, g07Uill, g08Uill; Uill g09Uill, g10Uill, g11Uill, g12Uill; Uill g13Uill, g14Uill, g15Uill, g16Uill; extern void initUill (Uill *p, int i); extern void checkgUill (void); extern Uill test0Uill (void); extern Uill test1Uill (Uill); extern Uill testvaUill (int n, ...); void testitUill (void) { Uill rslt; ; ; initUill (&g01Uill, 1); initUill (&g02Uill, 2); initUill (&g03Uill, 3); initUill (&g04Uill, 4); initUill (&g05Uill, 5); initUill (&g06Uill, 6); initUill (&g07Uill, 7); initUill (&g08Uill, 8); initUill (&g09Uill, 9); initUill (&g10Uill, 10); initUill (&g11Uill, 11); initUill (&g12Uill, 12); initUill (&g13Uill, 13); initUill (&g14Uill, 14); initUill (&g15Uill, 15); initUill (&g16Uill, 16); checkgUill (); ; ; ; rslt = test0Uill (); checkUill (rslt, 1); ; ; ; rslt = test1Uill (g01Uill); checkUill (rslt, 1); if (test_va) { ; ; ; rslt = testvaUill (1, g01Uill); checkUill (rslt, 1); rslt = testvaUill (5, g01Uill, g02Uill, g03Uill, g04Uill, g05Uill); checkUill (rslt, 5); rslt = testvaUill (9, g01Uill, g02Uill, g03Uill, g04Uill, g05Uill, g06Uill, g07Uill, g08Uill, g09Uill); checkUill (rslt, 9); rslt = testvaUill (16, g01Uill, g02Uill, g03Uill, g04Uill, g05Uill, g06Uill, g07Uill, g08Uill, g09Uill, g10Uill, g11Uill, g12Uill, g13Uill, g14Uill, g15Uill, g16Uill); checkUill (rslt, 16); } ; }
Ulll g01Ulll, g02Ulll, g03Ulll, g04Ulll; Ulll g05Ulll, g06Ulll, g07Ulll, g08Ulll; Ulll g09Ulll, g10Ulll, g11Ulll, g12Ulll; Ulll g13Ulll, g14Ulll, g15Ulll, g16Ulll; extern void initUlll (Ulll *p, int i); extern void checkgUlll (void); extern Ulll test0Ulll (void); extern Ulll test1Ulll (Ulll); extern Ulll testvaUlll (int n, ...); void testitUlll (void) { Ulll rslt; ; ; initUlll (&g01Ulll, 1); initUlll (&g02Ulll, 2); initUlll (&g03Ulll, 3); initUlll (&g04Ulll, 4); initUlll (&g05Ulll, 5); initUlll (&g06Ulll, 6); initUlll (&g07Ulll, 7); initUlll (&g08Ulll, 8); initUlll (&g09Ulll, 9); initUlll (&g10Ulll, 10); initUlll (&g11Ulll, 11); initUlll (&g12Ulll, 12); initUlll (&g13Ulll, 13); initUlll (&g14Ulll, 14); initUlll (&g15Ulll, 15); initUlll (&g16Ulll, 16); checkgUlll (); ; ; ; rslt = test0Ulll (); checkUlll (rslt, 1); ; ; ; rslt = test1Ulll (g01Ulll); checkUlll (rslt, 1); if (test_va) { ; ; ; rslt = testvaUlll (1, g01Ulll); checkUlll (rslt, 1); rslt = testvaUlll (5, g01Ulll, g02Ulll, g03Ulll, g04Ulll, g05Ulll); checkUlll (rslt, 5); rslt = testvaUlll (9, g01Ulll, g02Ulll, g03Ulll, g04Ulll, g05Ulll, g06Ulll, g07Ulll, g08Ulll, g09Ulll); checkUlll (rslt, 9); rslt = testvaUlll (16, g01Ulll, g02Ulll, g03Ulll, g04Ulll, g05Ulll, g06Ulll, g07Ulll, g08Ulll, g09Ulll, g10Ulll, g11Ulll, g12Ulll, g13Ulll, g14Ulll, g15Ulll, g16Ulll); checkUlll (rslt, 16); } ; }



void
union_return_1_x ()
{




testitUcs ();
testitUci ();
testitUcl ();
testitUcll ();
testitUsi ();
testitUsl ();
testitUsll ();
testitUil ();
testitUill ();
testitUlll ();



if (fails != 0)
  abort ();


}
