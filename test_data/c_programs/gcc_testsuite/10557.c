union ui2 {
  int si[16];
  unsigned int ui[16];
};

union us {
  short ss[16];
  unsigned short us[16];
};

static union ui2 i32_sa __attribute__((__aligned__(32)));
static union ui2 i32_ua __attribute__((__aligned__(32)));

static union us i16_b __attribute__((__aligned__(32))) = {
  (short)1,
  (short)23,
  (short)345,
  (short)6789,
  (short)1011,
  (short)-12,
  (short)1314,
  (short)-1516,
  (short)-1516,
  (short)1314,
  (short)-12,
  (short)1011,
  (short)6789,
  (short)345,
  (short)23,
  (short)1,
};

static union us i16_c __attribute__((__aligned__(32))) = {
  (short)2,
  (short)31567,
  (short)1112,
  (short)13,
  (short)14,
  (short)15,
  (short)-16,
  (short)17,
  (short)2,
  (short)31567,
  (short)1112,
  (short)13,
  (short)14,
  (short)15,
  (short)-16,
  (short)17,
};

static long i32_sr[16] __attribute__((__aligned__(32))) = {
  ((int)1) * ((int)2),
  ((int)23) * ((int)31567),
  ((int)345) * ((int)1112),
  ((int)6789) * ((int)13),
  ((int)1011) * ((int)14),
  ((int)-12) * ((int)15),
  ((int)1314) * ((int)-16),
  ((int)-1516) * ((int)17),
  ((int)-1516) * ((int)2),
  ((int)1314) * ((int)31567),
  ((int)-12) * ((int)1112),
  ((int)1011) * ((int)13),
  ((int)6789) * ((int)14),
  ((int)345) * ((int)15),
  ((int)23) * ((int)-16),
  ((int)1) * ((int)17),
};

static unsigned long i32_ur[16] __attribute__((__aligned__(32))) = {
  ((unsigned int)(unsigned short)1) * ((unsigned int)(unsigned short)2),
  ((unsigned int)(unsigned short)23) * ((unsigned int)(unsigned short)31567),
  ((unsigned int)(unsigned short)345) * ((unsigned int)(unsigned short)1112),
  ((unsigned int)(unsigned short)6789) * ((unsigned int)(unsigned short)13),
  ((unsigned int)(unsigned short)1011) * ((unsigned int)(unsigned short)14),
  ((unsigned int)(unsigned short)-12) * ((unsigned int)(unsigned short)15),
  ((unsigned int)(unsigned short)1314) * ((unsigned int)(unsigned short)-16),
  ((unsigned int)(unsigned short)-1516) * ((unsigned int)(unsigned short)17),
  ((unsigned int)(unsigned short)-1516) * ((unsigned int)(unsigned short)2),
  ((unsigned int)(unsigned short)1314) * ((unsigned int)(unsigned short)31567),
  ((unsigned int)(unsigned short)-12) * ((unsigned int)(unsigned short)1112),
  ((unsigned int)(unsigned short)1011) * ((unsigned int)(unsigned short)13),
  ((unsigned int)(unsigned short)6789) * ((unsigned int)(unsigned short)14),
  ((unsigned int)(unsigned short)345) * ((unsigned int)(unsigned short)15),
  ((unsigned int)(unsigned short)23) * ((unsigned int)(unsigned short)-16),
  ((unsigned int)(unsigned short)1) * ((unsigned int)(unsigned short)17),
};
union ul {
  long sl[8];
  unsigned long ul[8];
};

union ui {
  int si[8];
  unsigned int ui[8];
};

static union ul i64_sa __attribute__((__aligned__(32)));
static union ul i64_ua __attribute__((__aligned__(32)));

static union ui i32_b __attribute__((__aligned__(32))) = {
  (int)1,
  (int)23,
  (int)345,
  (int)6789,
  (int)101112,
  (int)-13,
  (int)141516,
  (int)-1718,
};

static union ui i32_c __attribute__((__aligned__(32))) = {
  (int)2,
  (int)45678910,
  (int)1112,
  (int)13,
  (int)14,
  (int)15,
  (int)-16,
  (int)17,
};

static long i64_sr[8] __attribute__((__aligned__(32))) = {
  ((long)1) * ((long)2),
  ((long)23) * ((long)45678910),
  ((long)345) * ((long)1112),
  ((long)6789) * ((long)13),
  ((long)101112) * ((long)14),
  ((long)-13) * ((long)15),
  ((long)141516) * ((long)-16),
  ((long)-1718) * ((long)17),
};

static unsigned long i64_ur[8] __attribute__((__aligned__(32))) = {
  ((unsigned long)(unsigned)1) * ((unsigned long)(unsigned)2),
  ((unsigned long)(unsigned)23) * ((unsigned long)(unsigned)45678910),
  ((unsigned long)(unsigned)345) * ((unsigned long)(unsigned)1112),
  ((unsigned long)(unsigned)6789) * ((unsigned long)(unsigned)13),
  ((unsigned long)(unsigned)101112) * ((unsigned long)(unsigned)14),
  ((unsigned long)(unsigned)-13) * ((unsigned long)(unsigned)15),
  ((unsigned long)(unsigned)141516) * ((unsigned long)(unsigned)-16),
  ((unsigned long)(unsigned)-1718) * ((unsigned long)(unsigned)17),
};


int main ()
{
  int i;


  for (i = 0; i < 16; i++)
    i32_sa.si[i] = ((long)i16_b.ss[i]) * ((long)i16_c.ss[i]);

  for (i = 0; i < 16; i++)
    if (i32_sa.si[i] != i32_sr[i])
      __builtin_abort ();


  for (i = 0; i < 16; i++)
    i32_ua.ui[i] = ((long)i16_b.us[i]) * ((long)i16_c.us[i]);

  for (i = 0; i < 16; i++)
    if (i32_ua.ui[i] != i32_ur[i])
      __builtin_abort ();


  for (i = 0; i < 8; i++)
    i64_sa.sl[i] = ((long)i32_b.si[i]) * ((long)i32_c.si[i]);

  for (i = 0; i < 8; i++)
    if (i64_sa.sl[i] != i64_sr[i])
      __builtin_abort ();


  for (i = 0; i < 8; i++)
    i64_ua.ul[i] = ((long)i32_b.ui[i]) * ((long)i32_c.ui[i]);

  for (i = 0; i < 8; i++)
    if (i64_ua.ul[i] != i64_ur[i])
      __builtin_abort ();

  return 0;
}
