extern void abort (void);

extern int fails;
_Complex char g01cc; extern void initcc (_Complex char *p, _Complex char v); extern void checkgcc (void); extern _Complex char test0cc (void); extern _Complex char test1cc (_Complex char); void checkcc (_Complex char x, _Complex char v) { if (x != v) abort (); } void testitcc (void) { _Complex char rslt; ; ; initcc (&g01cc, 1); checkgcc (); ; ; ; rslt = test0cc (); checkcc (rslt, g01cc); ; ; ; rslt = test1cc (g01cc); checkcc (rslt, g01cc); ; }
_Complex short g01cs; extern void initcs (_Complex short *p, _Complex short v); extern void checkgcs (void); extern _Complex short test0cs (void); extern _Complex short test1cs (_Complex short); void checkcs (_Complex short x, _Complex short v) { if (x != v) abort (); } void testitcs (void) { _Complex short rslt; ; ; initcs (&g01cs, 1); checkgcs (); ; ; ; rslt = test0cs (); checkcs (rslt, g01cs); ; ; ; rslt = test1cs (g01cs); checkcs (rslt, g01cs); ; }

_Complex float g01cf; extern void initcf (_Complex float *p, _Complex float v); extern void checkgcf (void); extern _Complex float test0cf (void); extern _Complex float test1cf (_Complex float); void checkcf (_Complex float x, _Complex float v) { if (x != v) abort (); } void testitcf (void) { _Complex float rslt; ; ; initcf (&g01cf, 1); checkgcf (); ; ; ; rslt = test0cf (); checkcf (rslt, g01cf); ; ; ; rslt = test1cf (g01cf); checkcf (rslt, g01cf); ; }




void
scalar_return_4_x ()
{






testitcc ();
testitcs ();

testitcf ();




if (fails != 0)
  abort ();


}
