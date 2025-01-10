


#include <stdbool.h>
#include <stdarg.h>

void
foo (va_list ap)
{
  va_arg (ap, bool);
}
