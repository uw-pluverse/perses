




extern void abort (void);
extern void exit (int);
int
main (void)
{
  do { struct { char c; _Bool v; } x; if (_Alignof (_Bool) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; char v; } x; if (_Alignof (char) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; signed char v; } x; if (_Alignof (signed char) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; unsigned char v; } x; if (_Alignof (unsigned char) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; signed short v; } x; if (_Alignof (signed short) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; unsigned short v; } x; if (_Alignof (unsigned short) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; signed int v; } x; if (_Alignof (signed int) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; unsigned int v; } x; if (_Alignof (unsigned int) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; signed long v; } x; if (_Alignof (signed long) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; unsigned long v; } x; if (_Alignof (unsigned long) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; signed long long v; } x; if (_Alignof (signed long long) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; unsigned long long v; } x; if (_Alignof (unsigned long long) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; float v; } x; if (_Alignof (float) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; double v; } x; if (_Alignof (double) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; long double v; } x; if (_Alignof (long double) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; _Complex float v; } x; if (_Alignof (_Complex float) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; _Complex double v; } x; if (_Alignof (_Complex double) > __alignof__ (x.v)) abort (); } while (0);
  do { struct { char c; _Complex long double v; } x; if (_Alignof (_Complex long double) > __alignof__ (x.v)) abort (); } while (0);
  exit (0);
}
