




extern void direct (void);
void foo(void (*indirect) (void))
{
  indirect ();
  direct ();
}
