int s1, s2, s3, s4, s5, s6, s7, s8;

void
f1 (void)
{
  int i;
 for (i = 0; i < 64; i++)
    ;
 for (i = 0; i < 64; i++)
    ;
 for (int j = 0; j < 64; j++)
    ;
 for (s1 = 0; s1 < 64; s1 += 2)
    ;
 for (i = 0; i < 64; i++)
    s2 = 2 * i;
 for (i = 0; i < 64; i++)
    ;
 for (s3 = 0; s3 < 64; s3++)
    for (s4 = 0; s4 < 3; s4++)
      ;
 for (i = 0; i < 64; i++)
    ;
 for (i = 0; i < 64; i++)
    ;
 for (s5 = 0; s5 < 64; s5++)
    ;
 for (i = 0; i < 64; i++)
    s8 = s7++;
}

void
f2 (void)
{
  int i;
 for (i = 0; i < 64; i++)
    ;
 for (i = 0; i < 64; i++)
    s6 += i;
}


