


struct data {
 volatile unsigned long *addr;
} *p;

int test()
{
 *p->addr;
 return 0;
}
