


extern void bark(void);

__attribute__((transaction_callable))
int foo()
{
      bark();
}
