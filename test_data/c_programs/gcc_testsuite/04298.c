int glob0, glob1;



char *a0[] = {"reg0", "indreg0", "imm0", "limm0",
  "adr0", "adrreg0", "adrx0", "regx0"};
char *a1[] = {"reg1", "indreg1", "imm1", "limm1",
  "adr1", "adrreg1", "adrx1", "regx1"};

main_compare ()
{
  int i0, i1;

  for (i0 = 0; i0 < 8; i0++)
    {
      for (i1 = 0; i1 < 8; i1++)
 {
   printf ("%s%s_cmp (r0, r1, x0, x1, p0, p1)\n", a0[i0], a1[i1]);
   printf ("type r0, r1;  type *p0, *p1;\n");
   printf ("{if (%s <= %s) return 1; else return 0;}\n\n",
    a0[i0], a1[i1], a0[i0]);
 }
    }
}

main_assign ()
{
  int i0, i1;

  for (i0 = 0; i0 < 8; i0++)
    {
      if (i0 < 2 || i0 > 3)
      for (i1 = 0; i1 < 8; i1++)
 {
   printf ("%s%s_set (r0, r1, x0, x1, p0, p1)\n", a0[i0], a1[i1]);
   printf ("type r0, r1;  type *p0, *p1;\n");
   printf ("{%s = %s;  }\n\n",
    a0[i0], a1[i1]);
 }
    }
}

main () {main_assign ();}
