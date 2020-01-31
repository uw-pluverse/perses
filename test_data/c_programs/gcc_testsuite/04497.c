



typedef signed long int S;
typedef unsigned long int U;







typedef __int128 W;





__attribute__((noinline, noclone)) S spses (S x, S y, int *ovf) { S res; *ovf = __builtin_add_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) U upueu (U x, U y, int *ovf) { U res; *ovf = __builtin_add_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) U spseu (S x, S y, int *ovf) { U res; *ovf = __builtin_add_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) S upues (U x, U y, int *ovf) { S res; *ovf = __builtin_add_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) S spues (S x, U y, int *ovf) { S res; *ovf = __builtin_add_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) S upses (U x, S y, int *ovf) { S res; *ovf = __builtin_add_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) U spueu (S x, U y, int *ovf) { U res; *ovf = __builtin_add_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) U upseu (U x, S y, int *ovf) { U res; *ovf = __builtin_add_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) S ssses (S x, S y, int *ovf) { S res; *ovf = __builtin_sub_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) U usueu (U x, U y, int *ovf) { U res; *ovf = __builtin_sub_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) U ssseu (S x, S y, int *ovf) { U res; *ovf = __builtin_sub_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) S usues (U x, U y, int *ovf) { S res; *ovf = __builtin_sub_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) S ssues (S x, U y, int *ovf) { S res; *ovf = __builtin_sub_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) S usses (U x, S y, int *ovf) { S res; *ovf = __builtin_sub_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) U ssueu (S x, U y, int *ovf) { U res; *ovf = __builtin_sub_overflow (x, y, &res); return res; }
__attribute__((noinline, noclone)) U usseu (U x, S y, int *ovf) { U res; *ovf = __builtin_sub_overflow (x, y, &res); return res; }

int
main ()
{

  int i, j;
  for (i = 0; i < ((unsigned char) ~0); i++)
    for (j = 0; j < ((unsigned char) ~0); j++)
      {
 S s1 = ((W) i << ((8 - 1) * 8)) + (-9223372036854775807L - 1);
 U u1 = ((W) i << ((8 - 1) * 8));
 S s2 = ((W) j << ((8 - 1) * 8)) + (-9223372036854775807L - 1);
 U u2 = ((W) j << ((8 - 1) * 8));
 W w;
 int ovf;





 w = ((W) s1) + ((W) s2); if (spses ( s1, s2, &ovf) != (S) w || ovf != (w != (S) w)) __builtin_abort ();
 w = ((W) u1) + ((W) u2); if (upueu ( u1, u2, &ovf) != (U) w || ovf != (w != (U) w)) __builtin_abort ();
 w = ((W) s1) + ((W) s2); if (spseu ( s1, s2, &ovf) != (U) w || ovf != (w != (U) w)) __builtin_abort ();
 w = ((W) u1) + ((W) u2); if (upues ( u1, u2, &ovf) != (S) w || ovf != (w != (S) w)) __builtin_abort ();
 w = ((W) s1) + ((W) u2); if (spues ( s1, u2, &ovf) != (S) w || ovf != (w != (S) w)) __builtin_abort ();
 w = ((W) u1) + ((W) s2); if (upses ( u1, s2, &ovf) != (S) w || ovf != (w != (S) w)) __builtin_abort ();
 w = ((W) s1) + ((W) u2); if (spueu ( s1, u2, &ovf) != (U) w || ovf != (w != (U) w)) __builtin_abort ();
 w = ((W) u1) + ((W) s2); if (upseu ( u1, s2, &ovf) != (U) w || ovf != (w != (U) w)) __builtin_abort ();
 w = ((W) s1) - ((W) s2); if (ssses ( s1, s2, &ovf) != (S) w || ovf != (w != (S) w)) __builtin_abort ();
 w = ((W) u1) - ((W) u2); if (usueu ( u1, u2, &ovf) != (U) w || ovf != (w != (U) w)) __builtin_abort ();
 w = ((W) s1) - ((W) s2); if (ssseu ( s1, s2, &ovf) != (U) w || ovf != (w != (U) w)) __builtin_abort ();
 w = ((W) u1) - ((W) u2); if (usues ( u1, u2, &ovf) != (S) w || ovf != (w != (S) w)) __builtin_abort ();
 w = ((W) s1) - ((W) u2); if (ssues ( s1, u2, &ovf) != (S) w || ovf != (w != (S) w)) __builtin_abort ();
 w = ((W) u1) - ((W) s2); if (usses ( u1, s2, &ovf) != (S) w || ovf != (w != (S) w)) __builtin_abort ();
 w = ((W) s1) - ((W) u2); if (ssueu ( s1, u2, &ovf) != (U) w || ovf != (w != (U) w)) __builtin_abort ();
 w = ((W) u1) - ((W) s2); if (usseu ( u1, s2, &ovf) != (U) w || ovf != (w != (U) w)) __builtin_abort ();
      }

  return 0;
}

