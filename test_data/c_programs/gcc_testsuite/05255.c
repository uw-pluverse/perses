


typedef struct { char f[4]; } __attribute__((aligned (4))) s;

void a(s *s1, s *s2)
{
  *s1 = *s2;
}
