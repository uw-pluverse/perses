char c = ((char)0xf234);
short s = ((short)0xf234);
int i = ((int)0xf234);
long l = ((long)0xf2345678L);
long long ll = ((long long)0xf2345678abcdef0LL);
int shift1 = 4;
int shift2 = ((sizeof (long long) * 8) - 4);

main ()
{
  if ((((c) >> (shift1)) | ((c) << ((sizeof (c) * 8) - (shift1)))) != (((((char)0xf234)) >> (4)) | ((((char)0xf234)) << ((sizeof (((char)0xf234)) * 8) - (4)))))
    abort ();

  if ((((c) >> (4)) | ((c) << ((sizeof (c) * 8) - (4)))) != (((((char)0xf234)) >> (4)) | ((((char)0xf234)) << ((sizeof (((char)0xf234)) * 8) - (4)))))
    abort ();

  if ((((s) >> (shift1)) | ((s) << ((sizeof (s) * 8) - (shift1)))) != (((((short)0xf234)) >> (4)) | ((((short)0xf234)) << ((sizeof (((short)0xf234)) * 8) - (4)))))
    abort ();

  if ((((s) >> (4)) | ((s) << ((sizeof (s) * 8) - (4)))) != (((((short)0xf234)) >> (4)) | ((((short)0xf234)) << ((sizeof (((short)0xf234)) * 8) - (4)))))
    abort ();

  if ((((i) >> (shift1)) | ((i) << ((sizeof (i) * 8) - (shift1)))) != (((((int)0xf234)) >> (4)) | ((((int)0xf234)) << ((sizeof (((int)0xf234)) * 8) - (4)))))
    abort ();

  if ((((i) >> (4)) | ((i) << ((sizeof (i) * 8) - (4)))) != (((((int)0xf234)) >> (4)) | ((((int)0xf234)) << ((sizeof (((int)0xf234)) * 8) - (4)))))
    abort ();

  if ((((l) >> (shift1)) | ((l) << ((sizeof (l) * 8) - (shift1)))) != (((((long)0xf2345678L)) >> (4)) | ((((long)0xf2345678L)) << ((sizeof (((long)0xf2345678L)) * 8) - (4)))))
    abort ();

  if ((((l) >> (4)) | ((l) << ((sizeof (l) * 8) - (4)))) != (((((long)0xf2345678L)) >> (4)) | ((((long)0xf2345678L)) << ((sizeof (((long)0xf2345678L)) * 8) - (4)))))
    abort ();

  if ((((ll) >> (shift1)) | ((ll) << ((sizeof (ll) * 8) - (shift1)))) != (((((long long)0xf2345678abcdef0LL)) >> (4)) | ((((long long)0xf2345678abcdef0LL)) << ((sizeof (((long long)0xf2345678abcdef0LL)) * 8) - (4)))))
    abort ();

  if ((((ll) >> (4)) | ((ll) << ((sizeof (ll) * 8) - (4)))) != (((((long long)0xf2345678abcdef0LL)) >> (4)) | ((((long long)0xf2345678abcdef0LL)) << ((sizeof (((long long)0xf2345678abcdef0LL)) * 8) - (4)))))
    abort ();

  if ((((ll) >> (shift2)) | ((ll) << ((sizeof (ll) * 8) - (shift2)))) != (((((long long)0xf2345678abcdef0LL)) >> (((sizeof (long long) * 8) - 4))) | ((((long long)0xf2345678abcdef0LL)) << ((sizeof (((long long)0xf2345678abcdef0LL)) * 8) - (((sizeof (long long) * 8) - 4))))))
    abort ();

  if ((((ll) >> (((sizeof (long long) * 8) - 4))) | ((ll) << ((sizeof (ll) * 8) - (((sizeof (long long) * 8) - 4))))) != (((((long long)0xf2345678abcdef0LL)) >> (((sizeof (long long) * 8) - 4))) | ((((long long)0xf2345678abcdef0LL)) << ((sizeof (((long long)0xf2345678abcdef0LL)) * 8) - (((sizeof (long long) * 8) - 4))))))
    abort ();

  if ((((c) << (shift1)) | ((c) >> ((sizeof (c) * 8) - (shift1)))) != (((((char)0xf234)) << (4)) | ((((char)0xf234)) >> ((sizeof (((char)0xf234)) * 8) - (4)))))
    abort ();

  if ((((c) << (4)) | ((c) >> ((sizeof (c) * 8) - (4)))) != (((((char)0xf234)) << (4)) | ((((char)0xf234)) >> ((sizeof (((char)0xf234)) * 8) - (4)))))
    abort ();

  if ((((s) << (shift1)) | ((s) >> ((sizeof (s) * 8) - (shift1)))) != (((((short)0xf234)) << (4)) | ((((short)0xf234)) >> ((sizeof (((short)0xf234)) * 8) - (4)))))
    abort ();

  if ((((s) << (4)) | ((s) >> ((sizeof (s) * 8) - (4)))) != (((((short)0xf234)) << (4)) | ((((short)0xf234)) >> ((sizeof (((short)0xf234)) * 8) - (4)))))
    abort ();

  if ((((i) << (shift1)) | ((i) >> ((sizeof (i) * 8) - (shift1)))) != (((((int)0xf234)) << (4)) | ((((int)0xf234)) >> ((sizeof (((int)0xf234)) * 8) - (4)))))
    abort ();

  if ((((i) << (4)) | ((i) >> ((sizeof (i) * 8) - (4)))) != (((((int)0xf234)) << (4)) | ((((int)0xf234)) >> ((sizeof (((int)0xf234)) * 8) - (4)))))
    abort ();

  if ((((l) << (shift1)) | ((l) >> ((sizeof (l) * 8) - (shift1)))) != (((((long)0xf2345678L)) << (4)) | ((((long)0xf2345678L)) >> ((sizeof (((long)0xf2345678L)) * 8) - (4)))))
    abort ();

  if ((((l) << (4)) | ((l) >> ((sizeof (l) * 8) - (4)))) != (((((long)0xf2345678L)) << (4)) | ((((long)0xf2345678L)) >> ((sizeof (((long)0xf2345678L)) * 8) - (4)))))
    abort ();

  if ((((ll) << (shift1)) | ((ll) >> ((sizeof (ll) * 8) - (shift1)))) != (((((long long)0xf2345678abcdef0LL)) << (4)) | ((((long long)0xf2345678abcdef0LL)) >> ((sizeof (((long long)0xf2345678abcdef0LL)) * 8) - (4)))))
    abort ();

  if ((((ll) << (4)) | ((ll) >> ((sizeof (ll) * 8) - (4)))) != (((((long long)0xf2345678abcdef0LL)) << (4)) | ((((long long)0xf2345678abcdef0LL)) >> ((sizeof (((long long)0xf2345678abcdef0LL)) * 8) - (4)))))
    abort ();

  if ((((ll) << (shift2)) | ((ll) >> ((sizeof (ll) * 8) - (shift2)))) != (((((long long)0xf2345678abcdef0LL)) << (((sizeof (long long) * 8) - 4))) | ((((long long)0xf2345678abcdef0LL)) >> ((sizeof (((long long)0xf2345678abcdef0LL)) * 8) - (((sizeof (long long) * 8) - 4))))))
    abort ();

  if ((((ll) << (((sizeof (long long) * 8) - 4))) | ((ll) >> ((sizeof (ll) * 8) - (((sizeof (long long) * 8) - 4))))) != (((((long long)0xf2345678abcdef0LL)) << (((sizeof (long long) * 8) - 4))) | ((((long long)0xf2345678abcdef0LL)) >> ((sizeof (((long long)0xf2345678abcdef0LL)) * 8) - (((sizeof (long long) * 8) - 4))))))
    abort ();

  exit (0);
}
