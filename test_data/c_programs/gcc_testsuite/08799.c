extern void abort (void);
__attribute__((noinline, noclone)) short foo1 (short arg){ short ret = 1; if (arg + 1 < ((!0) ? -(1 << (sizeof (char) * 8 - 1)) : 0) || arg + 1 > ((!0) ? ((1 << (sizeof (char) * 8 - 1)) - 1) : ((1 << (sizeof (char) * 8)) - 1))) return ret; arg = arg + 1; ret = (char)arg; return arg; };
__attribute__((noinline, noclone)) short foo2 (short arg){ short ret = 1; if (arg + 1 < ((!0) ? -(1 << (sizeof (char) * 8 - 1)) : 0) + 1 || arg + 1 > ((!0) ? ((1 << (sizeof (char) * 8 - 1)) - 1) : ((1 << (sizeof (char) * 8)) - 1)) - 1) return ret; arg = arg + 1; ret = (char)arg; return arg; };



__attribute__((noinline, noclone)) short foo3 (short arg){ short ret = -1; if (arg + 1 < ((!0) ? -(1 << (sizeof (short) * 8 - 1)) : 0) + 1 || arg + 1 > 100) return ret; arg = arg + -1; ret = (char)arg; return arg; };
__attribute__((noinline, noclone)) short foo4 (short arg){ short ret = 1; if (arg + 1 < 12 || arg + 1 > ((!0) ? ((1 << (sizeof (short) * 8 - 1)) - 1) : ((1 << (sizeof (short) * 8)) - 1)) + 1) return ret; arg = arg + 1; ret = (char)arg; return arg; };


__attribute__((noinline, noclone)) unsigned short foo5 (unsigned short arg){ unsigned short ret = 1; if (arg + 1 < ((!1) ? -(1 << (sizeof (char) * 8 - 1)) : 0) + 1 || arg + 1 > ((!1) ? ((1 << (sizeof (char) * 8 - 1)) - 1) : ((1 << (sizeof (char) * 8)) - 1)) - 1) return ret; arg = arg + 1; ret = (unsigned char)arg; return arg; };

__attribute__((noinline, noclone)) unsigned short foo6 (unsigned short arg){ unsigned short ret = 1; if (arg + 1 < ((!1) ? -(1 << (sizeof (char) * 8 - 1)) : 0) || arg + 1 > ((!1) ? ((1 << (sizeof (char) * 8 - 1)) - 1) : ((1 << (sizeof (char) * 8)) - 1))) return ret; arg = arg + 1; ret = (unsigned char)arg; return arg; };



__attribute__((noinline, noclone)) unsigned short foo7 (unsigned short arg){ unsigned short ret = 1; if (arg + 1 < ((!1) ? -(1 << (sizeof (short) * 8 - 1)) : 0) + 1 || arg + 1 > ((!1) ? ((1 << (sizeof (short) * 8 - 1)) - 1) : ((1 << (sizeof (short) * 8)) - 1)) - 1) return ret; arg = arg + 1; ret = (unsigned char)arg; return arg; };

__attribute__((noinline, noclone)) unsigned short foo8 (unsigned short arg){ unsigned short ret = 1; if (arg + 1 < ((!1) ? -(1 << (sizeof (short) * 8 - 1)) : 0) || arg + 1 > ((!1) ? ((1 << (sizeof (short) * 8 - 1)) - 1) : ((1 << (sizeof (short) * 8)) - 1))) return ret; arg = arg + 1; ret = (unsigned char)arg; return arg; };



__attribute__((noinline, noclone)) short foo9 (short arg){ short ret = -1; if (arg + 1 < 1 || arg + 1 > ((!1) ? ((1 << (sizeof (char) * 8 - 1)) - 1) : ((1 << (sizeof (char) * 8)) - 1)) - 1) return ret; arg = arg + -1; ret = (unsigned char)arg; return arg; };

__attribute__((noinline, noclone)) short foo10 (short arg){ short ret = 1; if (arg + 1 < 0 || arg + 1 > ((!1) ? ((1 << (sizeof (char) * 8 - 1)) - 1) : ((1 << (sizeof (char) * 8)) - 1))) return ret; arg = arg + 1; ret = (unsigned char)arg; return arg; };



__attribute__((noinline, noclone)) short foo11 (short arg){ short ret = 1; if (arg + 1 < ((!0) ? -(1 << (sizeof (char) * 8 - 1)) : 0) + 1 || arg + 1 > ((!0) ? ((1 << (sizeof (char) * 8 - 1)) - 1) : ((1 << (sizeof (char) * 8)) - 1)) - 1) return ret; arg = arg + 1; ret = (unsigned char)arg; return arg; };

__attribute__((noinline, noclone)) short foo12 (short arg){ short ret = 1; if (arg + 1 < ((!0) ? -(1 << (sizeof (char) * 8 - 1)) : 0) || arg + 1 > ((!0) ? ((1 << (sizeof (char) * 8 - 1)) - 1) : ((1 << (sizeof (char) * 8)) - 1))) return ret; arg = arg + 1; ret = (unsigned char)arg; return arg; };



__attribute__((noinline, noclone)) unsigned short foo13 (unsigned short arg){ unsigned short ret = 1; if (arg + 1 < ((!1) ? -(1 << (sizeof (char) * 8 - 1)) : 0) + 1 || arg + 1 > ((!0) ? ((1 << (sizeof (char) * 8 - 1)) - 1) : ((1 << (sizeof (char) * 8)) - 1)) - 1) return ret; arg = arg + 1; ret = (char)arg; return arg; };

__attribute__((noinline, noclone)) unsigned short foo14 (unsigned short arg){ unsigned short ret = 1; if (arg + 1 < ((!1) ? -(1 << (sizeof (char) * 8 - 1)) : 0) || arg + 1 > ((!0) ? ((1 << (sizeof (char) * 8 - 1)) - 1) : ((1 << (sizeof (char) * 8)) - 1))) return ret; arg = arg + 1; ret = (char)arg; return arg; };



__attribute__((noinline, noclone)) unsigned short foo15 (unsigned short arg){ unsigned short ret = 1; if (arg + 1 < ((!1) ? -(1 << (sizeof (char) * 8 - 1)) : 0) + 1 || arg + 1 > ((!1) ? ((1 << (sizeof (char) * 8 - 1)) - 1) : ((1 << (sizeof (char) * 8)) - 1)) - 1) return ret; arg = arg + 1; ret = (char)arg; return arg; };

__attribute__((noinline, noclone)) unsigned short foo16 (unsigned short arg){ unsigned short ret = 1; if (arg + 1 < ((!1) ? -(1 << (sizeof (char) * 8 - 1)) : 0) || arg + 1 > ((!1) ? ((1 << (sizeof (char) * 8 - 1)) - 1) : ((1 << (sizeof (char) * 8)) - 1))) return ret; arg = arg + 1; ret = (char)arg; return arg; };


int main ()
{


  if (foo1 (-32) != -31)
    abort ();

  if (foo2 (32) != 33)
    abort ();



  if (foo3 (-512) != -513)
    abort ();

  if (foo4 (512) != 513)
    abort ();



  if (foo5 (64) != 65)
    abort ();

  if (foo6 (64) != 65)
    abort ();



  if (foo7 (512) != 513)
    abort ();

  if (foo8 (512) != 513)
    abort ();



  if (foo9 (2) != 1)
    abort ();

  if (foo10 (2) != 3)
    abort ();



  if (foo11 (-125) != -124)
    abort ();

  if (foo12 (-125) != -124)
    abort ();



  if (foo13 (125) != 126)
    abort ();

  if (foo14 (125) != 126)
    abort ();



  if (foo15 (250) != 251)
    abort ();

  if (foo16 (250) != 251)
    abort ();

  return 0;
}
