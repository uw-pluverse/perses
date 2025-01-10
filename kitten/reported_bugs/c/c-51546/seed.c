


#include <x86intrin.h>

__attribute__ ((target("general-regs-only")))
void
foo1 (void)
{
  _serialize ();
}
