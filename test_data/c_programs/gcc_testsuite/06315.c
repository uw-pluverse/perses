






extern int f2 (char *, char *);
extern char *ss[];
extern char *cc;
void
f1 (char *dd, char *bb)
{
  char *sp = bb + 1;
  char *ap;
  int i;
  char *ee = 0;
  char *cp;

  for (i = 0, cp = cc; i < 42; i++)
    if (cp)
      {
 if (f2 (dd, "xx") || f2 (ss[i], "xx") || f2 (ss[i], "yy"))
   if (bb < cp)
     continue;
 ee = ss[i];
 break;
      }

  if (!ee)
    for (ap = cc; *ap; ap++)
      if (f2(ap, sp))
 {
   ee = ap;
   break;
 }

  cc = ee;
}
