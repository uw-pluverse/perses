void init_IRQ(void) __attribute__((weak, alias("native_init_IRQ")));
void native_init_IRQ(void) {}
