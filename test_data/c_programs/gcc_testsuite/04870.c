



volatile int *bar(void);

void f1(void)
{
 *bar() += 1;
}
