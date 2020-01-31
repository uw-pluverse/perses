


int foo (int a)
{
void *p;
if (a!=0)
  p = &&L0;
else
  p = &&L1;
goto *p;
L0:
return 1;
L1:
return 0;
}
