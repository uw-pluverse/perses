






extern void prints (char *);

void __attribute__ ((interrupt ("IRQ"))) dm3730_IRQHandler(void)
{
    prints("IRQ" );
}
