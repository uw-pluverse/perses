



void
div3 (void)
{
    double tmp1;

    asm volatile ("fscale":"=t" (tmp1):"0" (0), "u" (0));
}
