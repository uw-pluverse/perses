void __attribute__ ((interrupt))
handler0 (void)
{
}

void __attribute__ ((interrupt("you load too")))
handler1 (void)
{
}

void __attribute__ ((interrupt(42)))
hander2 (void)
{
}
