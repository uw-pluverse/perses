





extern volatile unsigned long timer_ticks;

unsigned long ticks;

unsigned tst_read( unsigned char idx )
{
        switch( idx )
        {
                case 0x62: return (((unsigned long)(timer_ticks-ticks))/10);
                case 0x61: return timer_ticks;
                default: return 0;
        }
}
