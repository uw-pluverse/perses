





extern void abort (void);

volatile int i = 10;
volatile int j = 10;

int main()
{
        int k = i % j;
        if (k != 0) abort();
 return 0;
}
