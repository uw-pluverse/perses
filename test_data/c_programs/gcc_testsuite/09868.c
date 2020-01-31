typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

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
extern void checkUcs (Ucs x, int i); extern Ucs g1sUcs, g2sUcs, g3sUcs, g4sUcs; extern Ucs g5sUcs, g6sUcs, g7sUcs, g8sUcs; extern Ucs g9sUcs, g10sUcs, g11sUcs, g12sUcs; extern Ucs g13sUcs, g14sUcs, g15sUcs, g16sUcs; void checkgUcs (void) { checkUcs ( g1sUcs, 1); checkUcs ( g2sUcs, 2); checkUcs ( g3sUcs, 3); checkUcs ( g4sUcs, 4); checkUcs ( g5sUcs, 5); checkUcs ( g6sUcs, 6); checkUcs ( g7sUcs, 7); checkUcs ( g8sUcs, 8); checkUcs ( g9sUcs, 9); checkUcs ( g10sUcs, 10); checkUcs ( g11sUcs, 11); checkUcs ( g12sUcs, 12); checkUcs ( g13sUcs, 13); checkUcs ( g14sUcs, 14); checkUcs ( g15sUcs, 15); checkUcs ( g16sUcs, 16); } void testUcs (Ucs s1, Ucs s2, Ucs s3, Ucs s4, Ucs s5, Ucs s6, Ucs s7, Ucs s8, Ucs s9, Ucs s10, Ucs s11, Ucs s12, Ucs s13, Ucs s14, Ucs s15, Ucs s16) { checkUcs (s1, 1); checkUcs (s2, 2); checkUcs (s3, 3); checkUcs (s4, 4); checkUcs (s5, 5); checkUcs (s6, 6); checkUcs (s7, 7); checkUcs (s8, 8); checkUcs (s9, 9); checkUcs (s10, 10); checkUcs (s11, 11); checkUcs (s12, 12); checkUcs (s13, 13); checkUcs (s14, 14); checkUcs (s15, 15); checkUcs (s16, 16); } void testvaUcs (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Ucs t = __builtin_va_arg(ap, Ucs); checkUcs (t, i+1); } __builtin_va_end(ap); } }
extern void checkUci (Uci x, int i); extern Uci g1sUci, g2sUci, g3sUci, g4sUci; extern Uci g5sUci, g6sUci, g7sUci, g8sUci; extern Uci g9sUci, g10sUci, g11sUci, g12sUci; extern Uci g13sUci, g14sUci, g15sUci, g16sUci; void checkgUci (void) { checkUci ( g1sUci, 1); checkUci ( g2sUci, 2); checkUci ( g3sUci, 3); checkUci ( g4sUci, 4); checkUci ( g5sUci, 5); checkUci ( g6sUci, 6); checkUci ( g7sUci, 7); checkUci ( g8sUci, 8); checkUci ( g9sUci, 9); checkUci ( g10sUci, 10); checkUci ( g11sUci, 11); checkUci ( g12sUci, 12); checkUci ( g13sUci, 13); checkUci ( g14sUci, 14); checkUci ( g15sUci, 15); checkUci ( g16sUci, 16); } void testUci (Uci s1, Uci s2, Uci s3, Uci s4, Uci s5, Uci s6, Uci s7, Uci s8, Uci s9, Uci s10, Uci s11, Uci s12, Uci s13, Uci s14, Uci s15, Uci s16) { checkUci (s1, 1); checkUci (s2, 2); checkUci (s3, 3); checkUci (s4, 4); checkUci (s5, 5); checkUci (s6, 6); checkUci (s7, 7); checkUci (s8, 8); checkUci (s9, 9); checkUci (s10, 10); checkUci (s11, 11); checkUci (s12, 12); checkUci (s13, 13); checkUci (s14, 14); checkUci (s15, 15); checkUci (s16, 16); } void testvaUci (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Uci t = __builtin_va_arg(ap, Uci); checkUci (t, i+1); } __builtin_va_end(ap); } }
extern void checkUcl (Ucl x, int i); extern Ucl g1sUcl, g2sUcl, g3sUcl, g4sUcl; extern Ucl g5sUcl, g6sUcl, g7sUcl, g8sUcl; extern Ucl g9sUcl, g10sUcl, g11sUcl, g12sUcl; extern Ucl g13sUcl, g14sUcl, g15sUcl, g16sUcl; void checkgUcl (void) { checkUcl ( g1sUcl, 1); checkUcl ( g2sUcl, 2); checkUcl ( g3sUcl, 3); checkUcl ( g4sUcl, 4); checkUcl ( g5sUcl, 5); checkUcl ( g6sUcl, 6); checkUcl ( g7sUcl, 7); checkUcl ( g8sUcl, 8); checkUcl ( g9sUcl, 9); checkUcl ( g10sUcl, 10); checkUcl ( g11sUcl, 11); checkUcl ( g12sUcl, 12); checkUcl ( g13sUcl, 13); checkUcl ( g14sUcl, 14); checkUcl ( g15sUcl, 15); checkUcl ( g16sUcl, 16); } void testUcl (Ucl s1, Ucl s2, Ucl s3, Ucl s4, Ucl s5, Ucl s6, Ucl s7, Ucl s8, Ucl s9, Ucl s10, Ucl s11, Ucl s12, Ucl s13, Ucl s14, Ucl s15, Ucl s16) { checkUcl (s1, 1); checkUcl (s2, 2); checkUcl (s3, 3); checkUcl (s4, 4); checkUcl (s5, 5); checkUcl (s6, 6); checkUcl (s7, 7); checkUcl (s8, 8); checkUcl (s9, 9); checkUcl (s10, 10); checkUcl (s11, 11); checkUcl (s12, 12); checkUcl (s13, 13); checkUcl (s14, 14); checkUcl (s15, 15); checkUcl (s16, 16); } void testvaUcl (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Ucl t = __builtin_va_arg(ap, Ucl); checkUcl (t, i+1); } __builtin_va_end(ap); } }
extern void checkUcll (Ucll x, int i); extern Ucll g1sUcll, g2sUcll, g3sUcll, g4sUcll; extern Ucll g5sUcll, g6sUcll, g7sUcll, g8sUcll; extern Ucll g9sUcll, g10sUcll, g11sUcll, g12sUcll; extern Ucll g13sUcll, g14sUcll, g15sUcll, g16sUcll; void checkgUcll (void) { checkUcll ( g1sUcll, 1); checkUcll ( g2sUcll, 2); checkUcll ( g3sUcll, 3); checkUcll ( g4sUcll, 4); checkUcll ( g5sUcll, 5); checkUcll ( g6sUcll, 6); checkUcll ( g7sUcll, 7); checkUcll ( g8sUcll, 8); checkUcll ( g9sUcll, 9); checkUcll ( g10sUcll, 10); checkUcll ( g11sUcll, 11); checkUcll ( g12sUcll, 12); checkUcll ( g13sUcll, 13); checkUcll ( g14sUcll, 14); checkUcll ( g15sUcll, 15); checkUcll ( g16sUcll, 16); } void testUcll (Ucll s1, Ucll s2, Ucll s3, Ucll s4, Ucll s5, Ucll s6, Ucll s7, Ucll s8, Ucll s9, Ucll s10, Ucll s11, Ucll s12, Ucll s13, Ucll s14, Ucll s15, Ucll s16) { checkUcll (s1, 1); checkUcll (s2, 2); checkUcll (s3, 3); checkUcll (s4, 4); checkUcll (s5, 5); checkUcll (s6, 6); checkUcll (s7, 7); checkUcll (s8, 8); checkUcll (s9, 9); checkUcll (s10, 10); checkUcll (s11, 11); checkUcll (s12, 12); checkUcll (s13, 13); checkUcll (s14, 14); checkUcll (s15, 15); checkUcll (s16, 16); } void testvaUcll (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Ucll t = __builtin_va_arg(ap, Ucll); checkUcll (t, i+1); } __builtin_va_end(ap); } }
extern void checkUsi (Usi x, int i); extern Usi g1sUsi, g2sUsi, g3sUsi, g4sUsi; extern Usi g5sUsi, g6sUsi, g7sUsi, g8sUsi; extern Usi g9sUsi, g10sUsi, g11sUsi, g12sUsi; extern Usi g13sUsi, g14sUsi, g15sUsi, g16sUsi; void checkgUsi (void) { checkUsi ( g1sUsi, 1); checkUsi ( g2sUsi, 2); checkUsi ( g3sUsi, 3); checkUsi ( g4sUsi, 4); checkUsi ( g5sUsi, 5); checkUsi ( g6sUsi, 6); checkUsi ( g7sUsi, 7); checkUsi ( g8sUsi, 8); checkUsi ( g9sUsi, 9); checkUsi ( g10sUsi, 10); checkUsi ( g11sUsi, 11); checkUsi ( g12sUsi, 12); checkUsi ( g13sUsi, 13); checkUsi ( g14sUsi, 14); checkUsi ( g15sUsi, 15); checkUsi ( g16sUsi, 16); } void testUsi (Usi s1, Usi s2, Usi s3, Usi s4, Usi s5, Usi s6, Usi s7, Usi s8, Usi s9, Usi s10, Usi s11, Usi s12, Usi s13, Usi s14, Usi s15, Usi s16) { checkUsi (s1, 1); checkUsi (s2, 2); checkUsi (s3, 3); checkUsi (s4, 4); checkUsi (s5, 5); checkUsi (s6, 6); checkUsi (s7, 7); checkUsi (s8, 8); checkUsi (s9, 9); checkUsi (s10, 10); checkUsi (s11, 11); checkUsi (s12, 12); checkUsi (s13, 13); checkUsi (s14, 14); checkUsi (s15, 15); checkUsi (s16, 16); } void testvaUsi (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Usi t = __builtin_va_arg(ap, Usi); checkUsi (t, i+1); } __builtin_va_end(ap); } }
extern void checkUsl (Usl x, int i); extern Usl g1sUsl, g2sUsl, g3sUsl, g4sUsl; extern Usl g5sUsl, g6sUsl, g7sUsl, g8sUsl; extern Usl g9sUsl, g10sUsl, g11sUsl, g12sUsl; extern Usl g13sUsl, g14sUsl, g15sUsl, g16sUsl; void checkgUsl (void) { checkUsl ( g1sUsl, 1); checkUsl ( g2sUsl, 2); checkUsl ( g3sUsl, 3); checkUsl ( g4sUsl, 4); checkUsl ( g5sUsl, 5); checkUsl ( g6sUsl, 6); checkUsl ( g7sUsl, 7); checkUsl ( g8sUsl, 8); checkUsl ( g9sUsl, 9); checkUsl ( g10sUsl, 10); checkUsl ( g11sUsl, 11); checkUsl ( g12sUsl, 12); checkUsl ( g13sUsl, 13); checkUsl ( g14sUsl, 14); checkUsl ( g15sUsl, 15); checkUsl ( g16sUsl, 16); } void testUsl (Usl s1, Usl s2, Usl s3, Usl s4, Usl s5, Usl s6, Usl s7, Usl s8, Usl s9, Usl s10, Usl s11, Usl s12, Usl s13, Usl s14, Usl s15, Usl s16) { checkUsl (s1, 1); checkUsl (s2, 2); checkUsl (s3, 3); checkUsl (s4, 4); checkUsl (s5, 5); checkUsl (s6, 6); checkUsl (s7, 7); checkUsl (s8, 8); checkUsl (s9, 9); checkUsl (s10, 10); checkUsl (s11, 11); checkUsl (s12, 12); checkUsl (s13, 13); checkUsl (s14, 14); checkUsl (s15, 15); checkUsl (s16, 16); } void testvaUsl (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Usl t = __builtin_va_arg(ap, Usl); checkUsl (t, i+1); } __builtin_va_end(ap); } }
extern void checkUsll (Usll x, int i); extern Usll g1sUsll, g2sUsll, g3sUsll, g4sUsll; extern Usll g5sUsll, g6sUsll, g7sUsll, g8sUsll; extern Usll g9sUsll, g10sUsll, g11sUsll, g12sUsll; extern Usll g13sUsll, g14sUsll, g15sUsll, g16sUsll; void checkgUsll (void) { checkUsll ( g1sUsll, 1); checkUsll ( g2sUsll, 2); checkUsll ( g3sUsll, 3); checkUsll ( g4sUsll, 4); checkUsll ( g5sUsll, 5); checkUsll ( g6sUsll, 6); checkUsll ( g7sUsll, 7); checkUsll ( g8sUsll, 8); checkUsll ( g9sUsll, 9); checkUsll ( g10sUsll, 10); checkUsll ( g11sUsll, 11); checkUsll ( g12sUsll, 12); checkUsll ( g13sUsll, 13); checkUsll ( g14sUsll, 14); checkUsll ( g15sUsll, 15); checkUsll ( g16sUsll, 16); } void testUsll (Usll s1, Usll s2, Usll s3, Usll s4, Usll s5, Usll s6, Usll s7, Usll s8, Usll s9, Usll s10, Usll s11, Usll s12, Usll s13, Usll s14, Usll s15, Usll s16) { checkUsll (s1, 1); checkUsll (s2, 2); checkUsll (s3, 3); checkUsll (s4, 4); checkUsll (s5, 5); checkUsll (s6, 6); checkUsll (s7, 7); checkUsll (s8, 8); checkUsll (s9, 9); checkUsll (s10, 10); checkUsll (s11, 11); checkUsll (s12, 12); checkUsll (s13, 13); checkUsll (s14, 14); checkUsll (s15, 15); checkUsll (s16, 16); } void testvaUsll (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Usll t = __builtin_va_arg(ap, Usll); checkUsll (t, i+1); } __builtin_va_end(ap); } }
extern void checkUil (Uil x, int i); extern Uil g1sUil, g2sUil, g3sUil, g4sUil; extern Uil g5sUil, g6sUil, g7sUil, g8sUil; extern Uil g9sUil, g10sUil, g11sUil, g12sUil; extern Uil g13sUil, g14sUil, g15sUil, g16sUil; void checkgUil (void) { checkUil ( g1sUil, 1); checkUil ( g2sUil, 2); checkUil ( g3sUil, 3); checkUil ( g4sUil, 4); checkUil ( g5sUil, 5); checkUil ( g6sUil, 6); checkUil ( g7sUil, 7); checkUil ( g8sUil, 8); checkUil ( g9sUil, 9); checkUil ( g10sUil, 10); checkUil ( g11sUil, 11); checkUil ( g12sUil, 12); checkUil ( g13sUil, 13); checkUil ( g14sUil, 14); checkUil ( g15sUil, 15); checkUil ( g16sUil, 16); } void testUil (Uil s1, Uil s2, Uil s3, Uil s4, Uil s5, Uil s6, Uil s7, Uil s8, Uil s9, Uil s10, Uil s11, Uil s12, Uil s13, Uil s14, Uil s15, Uil s16) { checkUil (s1, 1); checkUil (s2, 2); checkUil (s3, 3); checkUil (s4, 4); checkUil (s5, 5); checkUil (s6, 6); checkUil (s7, 7); checkUil (s8, 8); checkUil (s9, 9); checkUil (s10, 10); checkUil (s11, 11); checkUil (s12, 12); checkUil (s13, 13); checkUil (s14, 14); checkUil (s15, 15); checkUil (s16, 16); } void testvaUil (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Uil t = __builtin_va_arg(ap, Uil); checkUil (t, i+1); } __builtin_va_end(ap); } }
extern void checkUill (Uill x, int i); extern Uill g1sUill, g2sUill, g3sUill, g4sUill; extern Uill g5sUill, g6sUill, g7sUill, g8sUill; extern Uill g9sUill, g10sUill, g11sUill, g12sUill; extern Uill g13sUill, g14sUill, g15sUill, g16sUill; void checkgUill (void) { checkUill ( g1sUill, 1); checkUill ( g2sUill, 2); checkUill ( g3sUill, 3); checkUill ( g4sUill, 4); checkUill ( g5sUill, 5); checkUill ( g6sUill, 6); checkUill ( g7sUill, 7); checkUill ( g8sUill, 8); checkUill ( g9sUill, 9); checkUill ( g10sUill, 10); checkUill ( g11sUill, 11); checkUill ( g12sUill, 12); checkUill ( g13sUill, 13); checkUill ( g14sUill, 14); checkUill ( g15sUill, 15); checkUill ( g16sUill, 16); } void testUill (Uill s1, Uill s2, Uill s3, Uill s4, Uill s5, Uill s6, Uill s7, Uill s8, Uill s9, Uill s10, Uill s11, Uill s12, Uill s13, Uill s14, Uill s15, Uill s16) { checkUill (s1, 1); checkUill (s2, 2); checkUill (s3, 3); checkUill (s4, 4); checkUill (s5, 5); checkUill (s6, 6); checkUill (s7, 7); checkUill (s8, 8); checkUill (s9, 9); checkUill (s10, 10); checkUill (s11, 11); checkUill (s12, 12); checkUill (s13, 13); checkUill (s14, 14); checkUill (s15, 15); checkUill (s16, 16); } void testvaUill (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Uill t = __builtin_va_arg(ap, Uill); checkUill (t, i+1); } __builtin_va_end(ap); } }
extern void checkUlll (Ulll x, int i); extern Ulll g1sUlll, g2sUlll, g3sUlll, g4sUlll; extern Ulll g5sUlll, g6sUlll, g7sUlll, g8sUlll; extern Ulll g9sUlll, g10sUlll, g11sUlll, g12sUlll; extern Ulll g13sUlll, g14sUlll, g15sUlll, g16sUlll; void checkgUlll (void) { checkUlll ( g1sUlll, 1); checkUlll ( g2sUlll, 2); checkUlll ( g3sUlll, 3); checkUlll ( g4sUlll, 4); checkUlll ( g5sUlll, 5); checkUlll ( g6sUlll, 6); checkUlll ( g7sUlll, 7); checkUlll ( g8sUlll, 8); checkUlll ( g9sUlll, 9); checkUlll ( g10sUlll, 10); checkUlll ( g11sUlll, 11); checkUlll ( g12sUlll, 12); checkUlll ( g13sUlll, 13); checkUlll ( g14sUlll, 14); checkUlll ( g15sUlll, 15); checkUlll ( g16sUlll, 16); } void testUlll (Ulll s1, Ulll s2, Ulll s3, Ulll s4, Ulll s5, Ulll s6, Ulll s7, Ulll s8, Ulll s9, Ulll s10, Ulll s11, Ulll s12, Ulll s13, Ulll s14, Ulll s15, Ulll s16) { checkUlll (s1, 1); checkUlll (s2, 2); checkUlll (s3, 3); checkUlll (s4, 4); checkUlll (s5, 5); checkUlll (s6, 6); checkUlll (s7, 7); checkUlll (s8, 8); checkUlll (s9, 9); checkUlll (s10, 10); checkUlll (s11, 11); checkUlll (s12, 12); checkUlll (s13, 13); checkUlll (s14, 14); checkUlll (s15, 15); checkUlll (s16, 16); } void testvaUlll (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Ulll t = __builtin_va_arg(ap, Ulll); checkUlll (t, i+1); } __builtin_va_end(ap); } }
