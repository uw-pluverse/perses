extern void abort (void);

extern int fails;




const int test_va = 1;
_Complex int g01ci, g02ci, g03ci, g04ci; _Complex int g05ci, g06ci, g07ci, g08ci; _Complex int g09ci, g10ci, g11ci, g12ci; _Complex int g13ci, g14ci, g15ci, g16ci; extern void initci (_Complex int *p, _Complex int v); extern void checkgci (void); extern _Complex int test0ci (void); extern _Complex int test1ci (_Complex int); extern _Complex int testvaci (int n, ...); void checkci (_Complex int x, _Complex int v) { if (x != v) abort (); } void testitci (void) { _Complex int rslt; ; ; initci (&g01ci, 1); initci (&g02ci, 2); initci (&g03ci, 3); initci (&g04ci, 4); initci (&g05ci, 5); initci (&g06ci, 6); initci (&g07ci, 7); initci (&g08ci, 8); initci (&g09ci, 9); initci (&g10ci, 10); initci (&g11ci, 11); initci (&g12ci, 12); initci (&g13ci, 13); initci (&g14ci, 14); initci (&g15ci, 15); initci (&g16ci, 16); checkgci (); ; ; ; rslt = test0ci (); checkci (rslt, g01ci); ; ; ; rslt = test1ci (g01ci); checkci (rslt, g01ci); if (test_va) { ; ; ; rslt = testvaci (1, g01ci); checkci (rslt, g01ci); rslt = testvaci (5, g01ci, g02ci, g03ci, g04ci, g05ci); checkci (rslt, g05ci); rslt = testvaci (9, g01ci, g02ci, g03ci, g04ci, g05ci, g06ci, g07ci, g08ci, g09ci); checkci (rslt, g09ci); rslt = testvaci (16, g01ci, g02ci, g03ci, g04ci, g05ci, g06ci, g07ci, g08ci, g09ci, g10ci, g11ci, g12ci, g13ci, g14ci, g15ci, g16ci); checkci (rslt, g16ci); } ; }
_Complex long g01cl, g02cl, g03cl, g04cl; _Complex long g05cl, g06cl, g07cl, g08cl; _Complex long g09cl, g10cl, g11cl, g12cl; _Complex long g13cl, g14cl, g15cl, g16cl; extern void initcl (_Complex long *p, _Complex long v); extern void checkgcl (void); extern _Complex long test0cl (void); extern _Complex long test1cl (_Complex long); extern _Complex long testvacl (int n, ...); void checkcl (_Complex long x, _Complex long v) { if (x != v) abort (); } void testitcl (void) { _Complex long rslt; ; ; initcl (&g01cl, 1); initcl (&g02cl, 2); initcl (&g03cl, 3); initcl (&g04cl, 4); initcl (&g05cl, 5); initcl (&g06cl, 6); initcl (&g07cl, 7); initcl (&g08cl, 8); initcl (&g09cl, 9); initcl (&g10cl, 10); initcl (&g11cl, 11); initcl (&g12cl, 12); initcl (&g13cl, 13); initcl (&g14cl, 14); initcl (&g15cl, 15); initcl (&g16cl, 16); checkgcl (); ; ; ; rslt = test0cl (); checkcl (rslt, g01cl); ; ; ; rslt = test1cl (g01cl); checkcl (rslt, g01cl); if (test_va) { ; ; ; rslt = testvacl (1, g01cl); checkcl (rslt, g01cl); rslt = testvacl (5, g01cl, g02cl, g03cl, g04cl, g05cl); checkcl (rslt, g05cl); rslt = testvacl (9, g01cl, g02cl, g03cl, g04cl, g05cl, g06cl, g07cl, g08cl, g09cl); checkcl (rslt, g09cl); rslt = testvacl (16, g01cl, g02cl, g03cl, g04cl, g05cl, g06cl, g07cl, g08cl, g09cl, g10cl, g11cl, g12cl, g13cl, g14cl, g15cl, g16cl); checkcl (rslt, g16cl); } ; }
_Complex long long g01cll, g02cll, g03cll, g04cll; _Complex long long g05cll, g06cll, g07cll, g08cll; _Complex long long g09cll, g10cll, g11cll, g12cll; _Complex long long g13cll, g14cll, g15cll, g16cll; extern void initcll (_Complex long long *p, _Complex long long v); extern void checkgcll (void); extern _Complex long long test0cll (void); extern _Complex long long test1cll (_Complex long long); extern _Complex long long testvacll (int n, ...); void checkcll (_Complex long long x, _Complex long long v) { if (x != v) abort (); } void testitcll (void) { _Complex long long rslt; ; ; initcll (&g01cll, 1); initcll (&g02cll, 2); initcll (&g03cll, 3); initcll (&g04cll, 4); initcll (&g05cll, 5); initcll (&g06cll, 6); initcll (&g07cll, 7); initcll (&g08cll, 8); initcll (&g09cll, 9); initcll (&g10cll, 10); initcll (&g11cll, 11); initcll (&g12cll, 12); initcll (&g13cll, 13); initcll (&g14cll, 14); initcll (&g15cll, 15); initcll (&g16cll, 16); checkgcll (); ; ; ; rslt = test0cll (); checkcll (rslt, g01cll); ; ; ; rslt = test1cll (g01cll); checkcll (rslt, g01cll); if (test_va) { ; ; ; rslt = testvacll (1, g01cll); checkcll (rslt, g01cll); rslt = testvacll (5, g01cll, g02cll, g03cll, g04cll, g05cll); checkcll (rslt, g05cll); rslt = testvacll (9, g01cll, g02cll, g03cll, g04cll, g05cll, g06cll, g07cll, g08cll, g09cll); checkcll (rslt, g09cll); rslt = testvacll (16, g01cll, g02cll, g03cll, g04cll, g05cll, g06cll, g07cll, g08cll, g09cll, g10cll, g11cll, g12cll, g13cll, g14cll, g15cll, g16cll); checkcll (rslt, g16cll); } ; }

_Complex double g01cd, g02cd, g03cd, g04cd; _Complex double g05cd, g06cd, g07cd, g08cd; _Complex double g09cd, g10cd, g11cd, g12cd; _Complex double g13cd, g14cd, g15cd, g16cd; extern void initcd (_Complex double *p, _Complex double v); extern void checkgcd (void); extern _Complex double test0cd (void); extern _Complex double test1cd (_Complex double); extern _Complex double testvacd (int n, ...); void checkcd (_Complex double x, _Complex double v) { if (x != v) abort (); } void testitcd (void) { _Complex double rslt; ; ; initcd (&g01cd, 1); initcd (&g02cd, 2); initcd (&g03cd, 3); initcd (&g04cd, 4); initcd (&g05cd, 5); initcd (&g06cd, 6); initcd (&g07cd, 7); initcd (&g08cd, 8); initcd (&g09cd, 9); initcd (&g10cd, 10); initcd (&g11cd, 11); initcd (&g12cd, 12); initcd (&g13cd, 13); initcd (&g14cd, 14); initcd (&g15cd, 15); initcd (&g16cd, 16); checkgcd (); ; ; ; rslt = test0cd (); checkcd (rslt, g01cd); ; ; ; rslt = test1cd (g01cd); checkcd (rslt, g01cd); if (test_va) { ; ; ; rslt = testvacd (1, g01cd); checkcd (rslt, g01cd); rslt = testvacd (5, g01cd, g02cd, g03cd, g04cd, g05cd); checkcd (rslt, g05cd); rslt = testvacd (9, g01cd, g02cd, g03cd, g04cd, g05cd, g06cd, g07cd, g08cd, g09cd); checkcd (rslt, g09cd); rslt = testvacd (16, g01cd, g02cd, g03cd, g04cd, g05cd, g06cd, g07cd, g08cd, g09cd, g10cd, g11cd, g12cd, g13cd, g14cd, g15cd, g16cd); checkcd (rslt, g16cd); } ; }
_Complex long double g01cld, g02cld, g03cld, g04cld; _Complex long double g05cld, g06cld, g07cld, g08cld; _Complex long double g09cld, g10cld, g11cld, g12cld; _Complex long double g13cld, g14cld, g15cld, g16cld; extern void initcld (_Complex long double *p, _Complex long double v); extern void checkgcld (void); extern _Complex long double test0cld (void); extern _Complex long double test1cld (_Complex long double); extern _Complex long double testvacld (int n, ...); void checkcld (_Complex long double x, _Complex long double v) { if (x != v) abort (); } void testitcld (void) { _Complex long double rslt; ; ; initcld (&g01cld, 1); initcld (&g02cld, 2); initcld (&g03cld, 3); initcld (&g04cld, 4); initcld (&g05cld, 5); initcld (&g06cld, 6); initcld (&g07cld, 7); initcld (&g08cld, 8); initcld (&g09cld, 9); initcld (&g10cld, 10); initcld (&g11cld, 11); initcld (&g12cld, 12); initcld (&g13cld, 13); initcld (&g14cld, 14); initcld (&g15cld, 15); initcld (&g16cld, 16); checkgcld (); ; ; ; rslt = test0cld (); checkcld (rslt, g01cld); ; ; ; rslt = test1cld (g01cld); checkcld (rslt, g01cld); if (test_va) { ; ; ; rslt = testvacld (1, g01cld); checkcld (rslt, g01cld); rslt = testvacld (5, g01cld, g02cld, g03cld, g04cld, g05cld); checkcld (rslt, g05cld); rslt = testvacld (9, g01cld, g02cld, g03cld, g04cld, g05cld, g06cld, g07cld, g08cld, g09cld); checkcld (rslt, g09cld); rslt = testvacld (16, g01cld, g02cld, g03cld, g04cld, g05cld, g06cld, g07cld, g08cld, g09cld, g10cld, g11cld, g12cld, g13cld, g14cld, g15cld, g16cld); checkcld (rslt, g16cld); } ; }




void
scalar_return_3_x ()
{






testitci ();
testitcl ();
testitcll ();

testitcd ();
testitcld ();




if (fails != 0)
  abort ();


}
