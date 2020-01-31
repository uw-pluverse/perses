




typedef struct cast_key_st
{
  unsigned int data[32];
} CAST_KEY;







unsigned int CAST_S_table[1024];






void
CAST_set_key (CAST_KEY * key)
{
  unsigned int x[16];
  unsigned int z[16];
  unsigned int k[32];
  unsigned int X[4] = {0,0,0,0}, Z[4];
  unsigned int l, *K = k;
  int i;
  for (i = 0; i < 16; i++)
    x[i] = 0;
  for (;;)
    {
      l = X[0] ^ (CAST_S_table + 000)[x[13]] ^ (CAST_S_table + 256)[x[15]] ^ (CAST_S_table + 512)[x[12]] ^ (CAST_S_table + 768)[x[14]] ^ (CAST_S_table + 512)[x[8]];
      Z[0/4]=l; z[0 +3]=(l )&0xff; z[0 +2]=(l>> 8)&0xff; z[0 +1]=(l>>16)&0xff; z[0 +0]=(l>>24)&0xff;;
      Z[4/4]=l; z[4 +3]=(l )&0xff; z[4 +2]=(l>> 8)&0xff; z[4 +1]=(l>>16)&0xff; z[4 +0]=(l>>24)&0xff;;
      Z[8/4]=l; z[8 +3]=(l )&0xff; z[8 +2]=(l>> 8)&0xff; z[8 +1]=(l>>16)&0xff; z[8 +0]=(l>>24)&0xff;;
      Z[12/4]=l; z[12 +3]=(l )&0xff; z[12 +2]=(l>> 8)&0xff; z[12 +1]=(l>>16)&0xff; z[12 +0]=(l>>24)&0xff;;
      K[0] = (CAST_S_table + 000)[z[8]] ^ (CAST_S_table + 256)[z[9]] ^ (CAST_S_table + 512)[z[7]] ^ (CAST_S_table + 768)[z[6]] ^ (CAST_S_table + 000)[z[2]];
      K[1] = (CAST_S_table + 000)[z[10]] ^ (CAST_S_table + 256)[z[11]] ^ (CAST_S_table + 512)[z[5]] ^ (CAST_S_table + 768)[z[4]] ^ (CAST_S_table + 256)[z[6]];
      K[2] = (CAST_S_table + 000)[z[12]] ^ (CAST_S_table + 256)[z[13]] ^ (CAST_S_table + 512)[z[3]] ^ (CAST_S_table + 768)[z[2]] ^ (CAST_S_table + 512)[z[9]];
      K[3] = (CAST_S_table + 000)[z[14]] ^ (CAST_S_table + 256)[z[15]] ^ (CAST_S_table + 512)[z[1]] ^ (CAST_S_table + 768)[z[0]] ^ (CAST_S_table + 768)[z[12]];
      K[4] = (CAST_S_table + 000)[x[3]] ^ (CAST_S_table + 256)[x[2]] ^ (CAST_S_table + 512)[x[12]] ^ (CAST_S_table + 768)[x[13]] ^ (CAST_S_table + 000)[x[8]];
      K[5] = (CAST_S_table + 000)[x[1]] ^ (CAST_S_table + 256)[x[0]] ^ (CAST_S_table + 512)[x[14]] ^ (CAST_S_table + 768)[x[15]] ^ (CAST_S_table + 256)[x[13]];
      K[6] = (CAST_S_table + 000)[x[7]] ^ (CAST_S_table + 256)[x[6]] ^ (CAST_S_table + 512)[x[8]] ^ (CAST_S_table + 768)[x[9]] ^ (CAST_S_table + 512)[x[3]];
      K[7] = (CAST_S_table + 000)[x[5]] ^ (CAST_S_table + 256)[x[4]] ^ (CAST_S_table + 512)[x[10]] ^ (CAST_S_table + 768)[x[11]] ^ (CAST_S_table + 768)[x[7]];
      K[8] = (CAST_S_table + 000)[z[3]] ^ (CAST_S_table + 256)[z[2]] ^ (CAST_S_table + 512)[z[12]] ^ (CAST_S_table + 768)[z[13]] ^ (CAST_S_table + 000)[z[9]];
      K[9] = (CAST_S_table + 000)[z[1]] ^ (CAST_S_table + 256)[z[0]] ^ (CAST_S_table + 512)[z[14]] ^ (CAST_S_table + 768)[z[15]] ^ (CAST_S_table + 256)[z[12]];
      K[10] = (CAST_S_table + 000)[z[7]] ^ (CAST_S_table + 256)[z[6]] ^ (CAST_S_table + 512)[z[8]] ^ (CAST_S_table + 768)[z[9]] ^ (CAST_S_table + 512)[z[2]];
      K[11] = (CAST_S_table + 000)[z[5]] ^ (CAST_S_table + 256)[z[4]] ^ (CAST_S_table + 512)[z[10]] ^ (CAST_S_table + 768)[z[11]] ^ (CAST_S_table + 768)[z[6]];
      l = Z[2] ^ (CAST_S_table + 000)[z[5]] ^ (CAST_S_table + 256)[z[7]] ^ (CAST_S_table + 512)[z[4]] ^ (CAST_S_table + 768)[z[6]] ^ (CAST_S_table + 512)[z[0]];
      X[0/4]=l; x[0 +3]=(l )&0xff; x[0 +2]=(l>> 8)&0xff; x[0 +1]=(l>>16)&0xff; x[0 +0]=(l>>24)&0xff;;
      K[12] = (CAST_S_table + 000)[x[8]] ^ (CAST_S_table + 256)[x[9]] ^ (CAST_S_table + 512)[x[7]] ^ (CAST_S_table + 768)[x[6]] ^ (CAST_S_table + 000)[x[3]];
      K[13] = (CAST_S_table + 000)[x[10]] ^ (CAST_S_table + 256)[x[11]] ^ (CAST_S_table + 512)[x[5]] ^ (CAST_S_table + 768)[x[4]] ^ (CAST_S_table + 256)[x[7]];
      K[14] = (CAST_S_table + 000)[x[12]] ^ (CAST_S_table + 256)[x[13]] ^ (CAST_S_table + 512)[x[3]] ^ (CAST_S_table + 768)[x[2]] ^ (CAST_S_table + 512)[x[8]];
      K[15] = (CAST_S_table + 000)[x[14]] ^ (CAST_S_table + 256)[x[15]] ^ (CAST_S_table + 512)[x[1]] ^ (CAST_S_table + 768)[x[0]] ^ (CAST_S_table + 768)[x[13]];
      if (K != k)
 break;
      K += 16;
    }
  for (i = 0; i < 16; i++)
    {
      key->data[i * 2] = k[i];
      key->data[i * 2 + 1] = ((k[i + 16]) + 16) & 0x1f;
    }
}

int
main ()
{
  CAST_KEY ref = { {0x0069B3F8, 0x00000013, 0x000AEFF8, 0x00000013, 0x004AD0E0, 0x0000001B, 0x00818F18, 0x00000018, 0x008FF000, 0x0000001B, 0x002D1C00, 0x0000001B, 0x00EA2800, 0x00000010, 0x00C73400, 0x00000010, 0x004BF8E0, 0x0000001B, 0x00B3D718, 0x00000018, 0x00B0EBF8, 0x00000013, 0x003247F8, 0x00000013, 0x00C5BA20, 0x00000010, 0x002D1C00, 0x00000010, 0x0060822B, 0x00000008, 0x0096236B, 0x0000001B} };
  CAST_KEY key;
  unsigned i;
  for (i = 1; i < 1024; i++)
    CAST_S_table[i] = (CAST_S_table[i-1] * 7 + 3) & 0xFFFFFF;
  CAST_set_key (&key);
  if (__builtin_memcmp(&ref, &key, sizeof(ref)))
    __builtin_abort();
  return 0;
}
