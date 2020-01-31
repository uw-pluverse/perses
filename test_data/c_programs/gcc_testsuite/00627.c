int sffoo4 (float x) { return x * 4.0f; } unsigned int usffoo4 (float x) { return x * 4.0f; } long lsffoo4 (float x) { return x * 4.0f; } unsigned long ulsffoo4 (float x) { return x * 4.0f; }
long dffoo4 (double x) { return x * 4.0; } unsigned long udffoo4 (double x) { return x * 4.0; } int sdffoo4 (double x) { return x * 4.0; } unsigned int usdffoo4 (double x) { return x * 4.0; }
int sffoo8 (float x) { return x * 8.0f; } unsigned int usffoo8 (float x) { return x * 8.0f; } long lsffoo8 (float x) { return x * 8.0f; } unsigned long ulsffoo8 (float x) { return x * 8.0f; }
long dffoo8 (double x) { return x * 8.0; } unsigned long udffoo8 (double x) { return x * 8.0; } int sdffoo8 (double x) { return x * 8.0; } unsigned int usdffoo8 (double x) { return x * 8.0; }
int sffoo16 (float x) { return x * 16.0f; } unsigned int usffoo16 (float x) { return x * 16.0f; } long lsffoo16 (float x) { return x * 16.0f; } unsigned long ulsffoo16 (float x) { return x * 16.0f; }
long dffoo16 (double x) { return x * 16.0; } unsigned long udffoo16 (double x) { return x * 16.0; } int sdffoo16 (double x) { return x * 16.0; } unsigned int usdffoo16 (double x) { return x * 16.0; }
int sffoo32 (float x) { return x * 32.0f; } unsigned int usffoo32 (float x) { return x * 32.0f; } long lsffoo32 (float x) { return x * 32.0f; } unsigned long ulsffoo32 (float x) { return x * 32.0f; }
long dffoo32 (double x) { return x * 32.0; } unsigned long udffoo32 (double x) { return x * 32.0; } int sdffoo32 (double x) { return x * 32.0; } unsigned int usdffoo32 (double x) { return x * 32.0; }
int
main (void)
{
  float i;

  for (i = -0.001; i < 32.0; i += 1.0f)
    {
      do { if (sffoo4 (i) != (int)(i * 4)) __builtin_abort (); if (usffoo4 (i) != (unsigned int)(i * 4)) __builtin_abort (); if (lsffoo4 (i) != (long)(i * 4)) __builtin_abort (); if (ulsffoo4 (i) != (unsigned long)(i * 4)) __builtin_abort (); } while (0);
      do { if (sffoo8 (i) != (int)(i * 8)) __builtin_abort (); if (usffoo8 (i) != (unsigned int)(i * 8)) __builtin_abort (); if (lsffoo8 (i) != (long)(i * 8)) __builtin_abort (); if (ulsffoo8 (i) != (unsigned long)(i * 8)) __builtin_abort (); } while (0);
      do { if (sffoo16 (i) != (int)(i * 16)) __builtin_abort (); if (usffoo16 (i) != (unsigned int)(i * 16)) __builtin_abort (); if (lsffoo16 (i) != (long)(i * 16)) __builtin_abort (); if (ulsffoo16 (i) != (unsigned long)(i * 16)) __builtin_abort (); } while (0);
      do { if (sffoo32 (i) != (int)(i * 32)) __builtin_abort (); if (usffoo32 (i) != (unsigned int)(i * 32)) __builtin_abort (); if (lsffoo32 (i) != (long)(i * 32)) __builtin_abort (); if (ulsffoo32 (i) != (unsigned long)(i * 32)) __builtin_abort (); } while (0);

      do { if (dffoo4 (i) != (long)(i * 4)) __builtin_abort (); if (udffoo4 (i) != (unsigned long)(i * 4)) __builtin_abort (); if (sdffoo4 (i) != (int)(i * 4)) __builtin_abort (); if (usdffoo4 (i) != (unsigned int)(i * 4)) __builtin_abort (); } while (0);
      do { if (dffoo8 (i) != (long)(i * 8)) __builtin_abort (); if (udffoo8 (i) != (unsigned long)(i * 8)) __builtin_abort (); if (sdffoo8 (i) != (int)(i * 8)) __builtin_abort (); if (usdffoo8 (i) != (unsigned int)(i * 8)) __builtin_abort (); } while (0);
      do { if (dffoo16 (i) != (long)(i * 16)) __builtin_abort (); if (udffoo16 (i) != (unsigned long)(i * 16)) __builtin_abort (); if (sdffoo16 (i) != (int)(i * 16)) __builtin_abort (); if (usdffoo16 (i) != (unsigned int)(i * 16)) __builtin_abort (); } while (0);
      do { if (dffoo32 (i) != (long)(i * 32)) __builtin_abort (); if (udffoo32 (i) != (unsigned long)(i * 32)) __builtin_abort (); if (sdffoo32 (i) != (int)(i * 32)) __builtin_abort (); if (usdffoo32 (i) != (unsigned int)(i * 32)) __builtin_abort (); } while (0);
    }
  return 0;
}
