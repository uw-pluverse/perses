







extern void abort (void);

volatile int i = 24;
volatile int j = 30;
volatile int k = 1;

int main()
{
        int pri2 = (((double) i / j) * (10000 / 1000) * k);
        if (pri2 != 8) abort();
 return 0;
}
