long offset;
void *handler;

extern void setup_offset(void);

void foo(void)
{
  __builtin_unwind_init ();
  setup_offset();
  __builtin_eh_return (offset, handler);
}
