



struct s { struct s *nxt; int v; } q;

int x[10];

int foo(int *p)
{
  int i = 0;


  (*p) = (*p)++;
  p[3] = p[3]++;
  p[i] = p[i]++;
  x[3] = x[3]++;
  q.nxt->nxt->v = q.nxt->nxt->v++;



  { int a = i-i++; (void)a;}

  if ((i-i++) != 0)
    return i-i++;

  for (i-i++;;)
    ;

  for (; (i-i++) != 0; )
    ;

  for (;;i-i++)
    ;

  while ((i-i++) != 0)
    ;

  do {} while ((i-i++) != 0);

  switch (i-i++) {
  case 0: return 1;
  }

  return 0;
}
