

int t(int a) __attribute__ ((const));
void abort (void);
int
ccp(int b)
{
 int a=1;
 a++;
 a++;
 a++;
 if (b)
   abort();
 return a;
}
