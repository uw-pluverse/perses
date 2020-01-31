

unsigned char uc = ((unsigned char)0x1234U);
unsigned short us = ((unsigned short)0x1234U);
unsigned int ui = 0x1234U;
unsigned long ul = 0x12345678LU;
unsigned long long ull = 0x12345678abcdef0LLU;
int shift1 = 4;
int shift2 = ((sizeof (long long) * 8) - 4);

main ()
{
  if ((((uc) >> (shift1)) | ((uc) << ((sizeof (uc) * 8) - (shift1)))) != (((((unsigned char)0x1234U)) >> (4)) | ((((unsigned char)0x1234U)) << ((sizeof (((unsigned char)0x1234U)) * 8) - (4)))))
    abort ();

  if ((((uc) >> (4)) | ((uc) << ((sizeof (uc) * 8) - (4)))) != (((((unsigned char)0x1234U)) >> (4)) | ((((unsigned char)0x1234U)) << ((sizeof (((unsigned char)0x1234U)) * 8) - (4)))))
    abort ();

  if ((((us) >> (shift1)) | ((us) << ((sizeof (us) * 8) - (shift1)))) != (((((unsigned short)0x1234U)) >> (4)) | ((((unsigned short)0x1234U)) << ((sizeof (((unsigned short)0x1234U)) * 8) - (4)))))
    abort ();

  if ((((us) >> (4)) | ((us) << ((sizeof (us) * 8) - (4)))) != (((((unsigned short)0x1234U)) >> (4)) | ((((unsigned short)0x1234U)) << ((sizeof (((unsigned short)0x1234U)) * 8) - (4)))))
    abort ();

  if ((((ui) >> (shift1)) | ((ui) << ((sizeof (ui) * 8) - (shift1)))) != (((0x1234U) >> (4)) | ((0x1234U) << ((sizeof (0x1234U) * 8) - (4)))))
    abort ();

  if ((((ui) >> (4)) | ((ui) << ((sizeof (ui) * 8) - (4)))) != (((0x1234U) >> (4)) | ((0x1234U) << ((sizeof (0x1234U) * 8) - (4)))))
    abort ();

  if ((((ul) >> (shift1)) | ((ul) << ((sizeof (ul) * 8) - (shift1)))) != (((0x12345678LU) >> (4)) | ((0x12345678LU) << ((sizeof (0x12345678LU) * 8) - (4)))))
    abort ();

  if ((((ul) >> (4)) | ((ul) << ((sizeof (ul) * 8) - (4)))) != (((0x12345678LU) >> (4)) | ((0x12345678LU) << ((sizeof (0x12345678LU) * 8) - (4)))))
    abort ();

  if ((((ull) >> (shift1)) | ((ull) << ((sizeof (ull) * 8) - (shift1)))) != (((0x12345678abcdef0LLU) >> (4)) | ((0x12345678abcdef0LLU) << ((sizeof (0x12345678abcdef0LLU) * 8) - (4)))))
    abort ();

  if ((((ull) >> (4)) | ((ull) << ((sizeof (ull) * 8) - (4)))) != (((0x12345678abcdef0LLU) >> (4)) | ((0x12345678abcdef0LLU) << ((sizeof (0x12345678abcdef0LLU) * 8) - (4)))))
    abort ();

  if ((((ull) >> (shift2)) | ((ull) << ((sizeof (ull) * 8) - (shift2)))) != (((0x12345678abcdef0LLU) >> (((sizeof (long long) * 8) - 4))) | ((0x12345678abcdef0LLU) << ((sizeof (0x12345678abcdef0LLU) * 8) - (((sizeof (long long) * 8) - 4))))))
    abort ();

  if ((((ull) >> (((sizeof (long long) * 8) - 4))) | ((ull) << ((sizeof (ull) * 8) - (((sizeof (long long) * 8) - 4))))) != (((0x12345678abcdef0LLU) >> (((sizeof (long long) * 8) - 4))) | ((0x12345678abcdef0LLU) << ((sizeof (0x12345678abcdef0LLU) * 8) - (((sizeof (long long) * 8) - 4))))))
    abort ();

  if ((((uc) << (shift1)) | ((uc) >> ((sizeof (uc) * 8) - (shift1)))) != (((((unsigned char)0x1234U)) << (4)) | ((((unsigned char)0x1234U)) >> ((sizeof (((unsigned char)0x1234U)) * 8) - (4)))))
    abort ();

  if ((((uc) << (4)) | ((uc) >> ((sizeof (uc) * 8) - (4)))) != (((((unsigned char)0x1234U)) << (4)) | ((((unsigned char)0x1234U)) >> ((sizeof (((unsigned char)0x1234U)) * 8) - (4)))))
    abort ();

  if ((((us) << (shift1)) | ((us) >> ((sizeof (us) * 8) - (shift1)))) != (((((unsigned short)0x1234U)) << (4)) | ((((unsigned short)0x1234U)) >> ((sizeof (((unsigned short)0x1234U)) * 8) - (4)))))
    abort ();

  if ((((us) << (4)) | ((us) >> ((sizeof (us) * 8) - (4)))) != (((((unsigned short)0x1234U)) << (4)) | ((((unsigned short)0x1234U)) >> ((sizeof (((unsigned short)0x1234U)) * 8) - (4)))))
    abort ();

  if ((((ui) << (shift1)) | ((ui) >> ((sizeof (ui) * 8) - (shift1)))) != (((0x1234U) << (4)) | ((0x1234U) >> ((sizeof (0x1234U) * 8) - (4)))))
    abort ();

  if ((((ui) << (4)) | ((ui) >> ((sizeof (ui) * 8) - (4)))) != (((0x1234U) << (4)) | ((0x1234U) >> ((sizeof (0x1234U) * 8) - (4)))))
    abort ();

  if ((((ul) << (shift1)) | ((ul) >> ((sizeof (ul) * 8) - (shift1)))) != (((0x12345678LU) << (4)) | ((0x12345678LU) >> ((sizeof (0x12345678LU) * 8) - (4)))))
    abort ();

  if ((((ul) << (4)) | ((ul) >> ((sizeof (ul) * 8) - (4)))) != (((0x12345678LU) << (4)) | ((0x12345678LU) >> ((sizeof (0x12345678LU) * 8) - (4)))))
    abort ();

  if ((((ull) << (shift1)) | ((ull) >> ((sizeof (ull) * 8) - (shift1)))) != (((0x12345678abcdef0LLU) << (4)) | ((0x12345678abcdef0LLU) >> ((sizeof (0x12345678abcdef0LLU) * 8) - (4)))))
    abort ();

  if ((((ull) << (4)) | ((ull) >> ((sizeof (ull) * 8) - (4)))) != (((0x12345678abcdef0LLU) << (4)) | ((0x12345678abcdef0LLU) >> ((sizeof (0x12345678abcdef0LLU) * 8) - (4)))))
    abort ();

  if ((((ull) << (shift2)) | ((ull) >> ((sizeof (ull) * 8) - (shift2)))) != (((0x12345678abcdef0LLU) << (((sizeof (long long) * 8) - 4))) | ((0x12345678abcdef0LLU) >> ((sizeof (0x12345678abcdef0LLU) * 8) - (((sizeof (long long) * 8) - 4))))))
    abort ();

  if ((((ull) << (((sizeof (long long) * 8) - 4))) | ((ull) >> ((sizeof (ull) * 8) - (((sizeof (long long) * 8) - 4))))) != (((0x12345678abcdef0LLU) << (((sizeof (long long) * 8) - 4))) | ((0x12345678abcdef0LLU) >> ((sizeof (0x12345678abcdef0LLU) * 8) - (((sizeof (long long) * 8) - 4))))))
    abort ();

  exit (0);
}
