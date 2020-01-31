



static const int var[4] = { 1, 2, 3, 4 };

void
foo (void)
{
  __asm volatile ("" : : "m" (*(int *) var));
}
