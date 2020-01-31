extern void abort (void);

extern int fails;
char g01c, g02c, g03c, g04c; char g05c, g06c, g07c, g08c; char g09c, g10c, g11c, g12c; char g13c, g14c, g15c, g16c; extern void initc (char *p, char v); extern void checkgc (void); extern char test0c (void); extern char test1c (char); void checkc (char x, char v) { if (x != v) abort (); } void testitc (void) { char rslt; ; ; initc (&g01c, 1); initc (&g02c, 2); initc (&g03c, 3); initc (&g04c, 4); initc (&g05c, 5); initc (&g06c, 6); initc (&g07c, 7); initc (&g08c, 8); initc (&g09c, 9); initc (&g10c, 10); initc (&g11c, 11); initc (&g12c, 12); initc (&g13c, 13); initc (&g14c, 14); initc (&g15c, 15); initc (&g16c, 16); checkgc (); ; ; ; rslt = test0c (); checkc (rslt, g01c); ; ; ; rslt = test1c (g01c); checkc (rslt, g01c); ; }
unsigned char g01uc, g02uc, g03uc, g04uc; unsigned char g05uc, g06uc, g07uc, g08uc; unsigned char g09uc, g10uc, g11uc, g12uc; unsigned char g13uc, g14uc, g15uc, g16uc; extern void inituc (unsigned char *p, unsigned char v); extern void checkguc (void); extern unsigned char test0uc (void); extern unsigned char test1uc (unsigned char); void checkuc (unsigned char x, unsigned char v) { if (x != v) abort (); } void testituc (void) { unsigned char rslt; ; ; inituc (&g01uc, 1); inituc (&g02uc, 2); inituc (&g03uc, 3); inituc (&g04uc, 4); inituc (&g05uc, 5); inituc (&g06uc, 6); inituc (&g07uc, 7); inituc (&g08uc, 8); inituc (&g09uc, 9); inituc (&g10uc, 10); inituc (&g11uc, 11); inituc (&g12uc, 12); inituc (&g13uc, 13); inituc (&g14uc, 14); inituc (&g15uc, 15); inituc (&g16uc, 16); checkguc (); ; ; ; rslt = test0uc (); checkuc (rslt, g01uc); ; ; ; rslt = test1uc (g01uc); checkuc (rslt, g01uc); ; }
signed char g01sc, g02sc, g03sc, g04sc; signed char g05sc, g06sc, g07sc, g08sc; signed char g09sc, g10sc, g11sc, g12sc; signed char g13sc, g14sc, g15sc, g16sc; extern void initsc (signed char *p, signed char v); extern void checkgsc (void); extern signed char test0sc (void); extern signed char test1sc (signed char); void checksc (signed char x, signed char v) { if (x != v) abort (); } void testitsc (void) { signed char rslt; ; ; initsc (&g01sc, 1); initsc (&g02sc, 2); initsc (&g03sc, 3); initsc (&g04sc, 4); initsc (&g05sc, 5); initsc (&g06sc, 6); initsc (&g07sc, 7); initsc (&g08sc, 8); initsc (&g09sc, 9); initsc (&g10sc, 10); initsc (&g11sc, 11); initsc (&g12sc, 12); initsc (&g13sc, 13); initsc (&g14sc, 14); initsc (&g15sc, 15); initsc (&g16sc, 16); checkgsc (); ; ; ; rslt = test0sc (); checksc (rslt, g01sc); ; ; ; rslt = test1sc (g01sc); checksc (rslt, g01sc); ; }
unsigned short g01us, g02us, g03us, g04us; unsigned short g05us, g06us, g07us, g08us; unsigned short g09us, g10us, g11us, g12us; unsigned short g13us, g14us, g15us, g16us; extern void initus (unsigned short *p, unsigned short v); extern void checkgus (void); extern unsigned short test0us (void); extern unsigned short test1us (unsigned short); void checkus (unsigned short x, unsigned short v) { if (x != v) abort (); } void testitus (void) { unsigned short rslt; ; ; initus (&g01us, 1); initus (&g02us, 2); initus (&g03us, 3); initus (&g04us, 4); initus (&g05us, 5); initus (&g06us, 6); initus (&g07us, 7); initus (&g08us, 8); initus (&g09us, 9); initus (&g10us, 10); initus (&g11us, 11); initus (&g12us, 12); initus (&g13us, 13); initus (&g14us, 14); initus (&g15us, 15); initus (&g16us, 16); checkgus (); ; ; ; rslt = test0us (); checkus (rslt, g01us); ; ; ; rslt = test1us (g01us); checkus (rslt, g01us); ; }
short g01ss, g02ss, g03ss, g04ss; short g05ss, g06ss, g07ss, g08ss; short g09ss, g10ss, g11ss, g12ss; short g13ss, g14ss, g15ss, g16ss; extern void initss (short *p, short v); extern void checkgss (void); extern short test0ss (void); extern short test1ss (short); void checkss (short x, short v) { if (x != v) abort (); } void testitss (void) { short rslt; ; ; initss (&g01ss, 1); initss (&g02ss, 2); initss (&g03ss, 3); initss (&g04ss, 4); initss (&g05ss, 5); initss (&g06ss, 6); initss (&g07ss, 7); initss (&g08ss, 8); initss (&g09ss, 9); initss (&g10ss, 10); initss (&g11ss, 11); initss (&g12ss, 12); initss (&g13ss, 13); initss (&g14ss, 14); initss (&g15ss, 15); initss (&g16ss, 16); checkgss (); ; ; ; rslt = test0ss (); checkss (rslt, g01ss); ; ; ; rslt = test1ss (g01ss); checkss (rslt, g01ss); ; }
float g01f, g02f, g03f, g04f; float g05f, g06f, g07f, g08f; float g09f, g10f, g11f, g12f; float g13f, g14f, g15f, g16f; extern void initf (float *p, float v); extern void checkgf (void); extern float test0f (void); extern float test1f (float); void checkf (float x, float v) { if (x != v) abort (); } void testitf (void) { float rslt; ; ; initf (&g01f, 1); initf (&g02f, 2); initf (&g03f, 3); initf (&g04f, 4); initf (&g05f, 5); initf (&g06f, 6); initf (&g07f, 7); initf (&g08f, 8); initf (&g09f, 9); initf (&g10f, 10); initf (&g11f, 11); initf (&g12f, 12); initf (&g13f, 13); initf (&g14f, 14); initf (&g15f, 15); initf (&g16f, 16); checkgf (); ; ; ; rslt = test0f (); checkf (rslt, g01f); ; ; ; rslt = test1f (g01f); checkf (rslt, g01f); ; }



void
scalar_return_2_x ()
{




testitc ();
testituc ();
testitsc ();
testitus ();
testitss ();
testitf ();



if (fails != 0)
  abort ();


}
