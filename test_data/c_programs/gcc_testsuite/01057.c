


void vector_18 (void)
{
    extern char slot;
    unsigned char status = (*(volatile unsigned char*) 0x2B);
    unsigned char data = (*(volatile unsigned char*) 0x2C);

    if (status & 0x10)
        slot = 0;
}
