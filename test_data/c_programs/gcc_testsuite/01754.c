



extern void abort (void);




int entry_calls, exit_calls;
void (*last_fn_entered)();
void (*last_fn_exited)();

__attribute__ ((noinline))
int main () __attribute__ ((no_instrument_function));

__attribute__ ((noinline))
void foo ()
{
  if (!(last_fn_entered == foo)) abort ();;
}

__attribute__ ((noinline))
static void foo2 ()
{
  if (!(entry_calls == 1 && exit_calls == 0)) abort ();;
  if (!(last_fn_entered == foo2)) abort ();;
  foo ();
  if (!(entry_calls == 2 && exit_calls == 1)) abort ();;
  if (!(last_fn_entered == foo)) abort ();;
  if (!(last_fn_exited == foo)) abort ();;
}

__attribute__ ((noinline))
void nfoo (void) __attribute__ ((no_instrument_function));
void nfoo ()
{
  if (!(entry_calls == 2 && exit_calls == 2)) abort ();;
  if (!(last_fn_entered == foo)) abort ();;
  if (!(last_fn_exited == foo2)) abort ();;
  foo ();
  if (!(entry_calls == 3 && exit_calls == 3)) abort ();;
  if (!(last_fn_entered == foo)) abort ();;
  if (!(last_fn_exited == foo)) abort ();;
}

int main ()
{
  if (!(entry_calls == 0 && exit_calls == 0)) abort ();;

  foo2 ();

  if (!(entry_calls == 2 && exit_calls == 2)) abort ();;
  if (!(last_fn_entered == foo)) abort ();;
  if (!(last_fn_exited == foo2)) abort ();;

  nfoo ();

  if (!(entry_calls == 3 && exit_calls == 3)) abort ();;
  if (!(last_fn_entered == foo)) abort ();;

  return 0;
}

void __cyg_profile_func_enter (void (*fn)(), void (*parent)()) __attribute__ ((no_instrument_function));
void __cyg_profile_func_exit (void (*fn)(), void (*parent)()) __attribute__ ((no_instrument_function));

__attribute__ ((noinline))
void __cyg_profile_func_enter (void (*fn)(), void (*parent)())
{
  entry_calls++;
  last_fn_entered = fn;
}
__attribute__ ((noinline))
void __cyg_profile_func_exit (void (*fn)(), void (*parent)())
{
  exit_calls++;
  last_fn_exited = fn;
}
