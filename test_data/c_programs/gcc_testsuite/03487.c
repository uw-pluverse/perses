

unsigned char glob0, glob1;
reg0reg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (r0 <= r1) return 1; else return 0;}

reg0indreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (r0 <= (*p1)) return 1; else return 0;}

reg0imm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (r0 <= 33) return 1; else return 0;}

reg0limm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (r0 <= ((unsigned char)&glob1)) return 1; else return 0;}

reg0adr1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (r0 <= (*((unsigned char *)11111111))) return 1; else return 0;}

reg0adrreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (r0 <= (p1[1111111/4])) return 1; else return 0;}

reg0adrx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (r0 <= (((unsigned char *)11111111)[x1])) return 1; else return 0;}

reg0regx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (r0 <= (p1[x1])) return 1; else return 0;}

indreg0reg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*p0) <= r1) return 1; else return 0;}

indreg0indreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*p0) <= (*p1)) return 1; else return 0;}

indreg0imm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*p0) <= 33) return 1; else return 0;}

indreg0limm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*p0) <= ((unsigned char)&glob1)) return 1; else return 0;}

indreg0adr1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*p0) <= (*((unsigned char *)11111111))) return 1; else return 0;}

indreg0adrreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*p0) <= (p1[1111111/4])) return 1; else return 0;}

indreg0adrx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*p0) <= (((unsigned char *)11111111)[x1])) return 1; else return 0;}

indreg0regx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*p0) <= (p1[x1])) return 1; else return 0;}

imm0reg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (22 <= r1) return 1; else return 0;}

imm0indreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (22 <= (*p1)) return 1; else return 0;}

imm0imm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (22 <= 33) return 1; else return 0;}

imm0limm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (22 <= ((unsigned char)&glob1)) return 1; else return 0;}

imm0adr1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (22 <= (*((unsigned char *)11111111))) return 1; else return 0;}

imm0adrreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (22 <= (p1[1111111/4])) return 1; else return 0;}

imm0adrx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (22 <= (((unsigned char *)11111111)[x1])) return 1; else return 0;}

imm0regx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (22 <= (p1[x1])) return 1; else return 0;}

limm0reg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (((unsigned char)&glob0) <= r1) return 1; else return 0;}

limm0indreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (((unsigned char)&glob0) <= (*p1)) return 1; else return 0;}

limm0imm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (((unsigned char)&glob0) <= 33) return 1; else return 0;}

limm0limm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (((unsigned char)&glob0) <= ((unsigned char)&glob1)) return 1; else return 0;}

limm0adr1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (((unsigned char)&glob0) <= (*((unsigned char *)11111111))) return 1; else return 0;}

limm0adrreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (((unsigned char)&glob0) <= (p1[1111111/4])) return 1; else return 0;}

limm0adrx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (((unsigned char)&glob0) <= (((unsigned char *)11111111)[x1])) return 1; else return 0;}

limm0regx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if (((unsigned char)&glob0) <= (p1[x1])) return 1; else return 0;}

adr0reg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*((unsigned char *)10000000)) <= r1) return 1; else return 0;}

adr0indreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*((unsigned char *)10000000)) <= (*p1)) return 1; else return 0;}

adr0imm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*((unsigned char *)10000000)) <= 33) return 1; else return 0;}

adr0limm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*((unsigned char *)10000000)) <= ((unsigned char)&glob1)) return 1; else return 0;}

adr0adr1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*((unsigned char *)10000000)) <= (*((unsigned char *)11111111))) return 1; else return 0;}

adr0adrreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*((unsigned char *)10000000)) <= (p1[1111111/4])) return 1; else return 0;}

adr0adrx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*((unsigned char *)10000000)) <= (((unsigned char *)11111111)[x1])) return 1; else return 0;}

adr0regx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((*((unsigned char *)10000000)) <= (p1[x1])) return 1; else return 0;}

adrreg0reg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[10000000]) <= r1) return 1; else return 0;}

adrreg0indreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[10000000]) <= (*p1)) return 1; else return 0;}

adrreg0imm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[10000000]) <= 33) return 1; else return 0;}

adrreg0limm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[10000000]) <= ((unsigned char)&glob1)) return 1; else return 0;}

adrreg0adr1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[10000000]) <= (*((unsigned char *)11111111))) return 1; else return 0;}

adrreg0adrreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[10000000]) <= (p1[1111111/4])) return 1; else return 0;}

adrreg0adrx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[10000000]) <= (((unsigned char *)11111111)[x1])) return 1; else return 0;}

adrreg0regx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[10000000]) <= (p1[x1])) return 1; else return 0;}

adrx0reg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((((unsigned char *)10000000)[x0]) <= r1) return 1; else return 0;}

adrx0indreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((((unsigned char *)10000000)[x0]) <= (*p1)) return 1; else return 0;}

adrx0imm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((((unsigned char *)10000000)[x0]) <= 33) return 1; else return 0;}

adrx0limm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((((unsigned char *)10000000)[x0]) <= ((unsigned char)&glob1)) return 1; else return 0;}

adrx0adr1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((((unsigned char *)10000000)[x0]) <= (*((unsigned char *)11111111))) return 1; else return 0;}

adrx0adrreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((((unsigned char *)10000000)[x0]) <= (p1[1111111/4])) return 1; else return 0;}

adrx0adrx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((((unsigned char *)10000000)[x0]) <= (((unsigned char *)11111111)[x1])) return 1; else return 0;}

adrx0regx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((((unsigned char *)10000000)[x0]) <= (p1[x1])) return 1; else return 0;}

regx0reg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[x0]) <= r1) return 1; else return 0;}

regx0indreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[x0]) <= (*p1)) return 1; else return 0;}

regx0imm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[x0]) <= 33) return 1; else return 0;}

regx0limm1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[x0]) <= ((unsigned char)&glob1)) return 1; else return 0;}

regx0adr1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[x0]) <= (*((unsigned char *)11111111))) return 1; else return 0;}

regx0adrreg1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[x0]) <= (p1[1111111/4])) return 1; else return 0;}

regx0adrx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[x0]) <= (((unsigned char *)11111111)[x1])) return 1; else return 0;}

regx0regx1 (r0, r1, x0, x1, p0, p1)
unsigned char r0, r1; unsigned char *p0, *p1;
{if ((p0[x0]) <= (p1[x1])) return 1; else return 0;}
