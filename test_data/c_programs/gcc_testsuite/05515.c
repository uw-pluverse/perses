


void foo (void)
{
void *p;
p = &&L0;
goto *p;
L0:
return;
}
