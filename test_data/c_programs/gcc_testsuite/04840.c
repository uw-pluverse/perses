



extern int b[];
void
foo (void)
{
  unsigned long v1, v2, v3;
 for (v1 = 0; v1 < 20; v1 += 2)
      for (v2 = 9223372036854775807L; v2 > 9223372036854775807L - 30; v2 -= 3)
 for (v3 = 10; v3 > 0; v3--)
 b[v3]++;
}

void
bar (void)
{
  unsigned long v1, v2, v3;
 for (v1 = 0; v1 < 20; v1 += 2)
      for (v2 = 9223372036854775807L; v2 > 9223372036854775807L - 30; v2 -= 3)
 for (v3 = 10; v3 > 0; v3--)
 b[v3]++;
}

void
baz (void)
{
  unsigned long v1, v2, v3;
 for (v1 = 0; v1 < 20; v1 += 2)
      for (v2 = 9223372036854775807L; v2 > 9223372036854775807L - 30; v2 -= 3)
 for (v3 = 10; v3 > 0; v3--)
 b[v3]++;
}
