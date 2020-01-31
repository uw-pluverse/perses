





struct gdb_exception
{
  int reason;
};
int catch_exceptions_with_msg (int *gdberrmsg)
{
  volatile struct gdb_exception exception;
  exceptions_state_mc_init (&(exception));
  if (exception.reason != 0)
    foo ();
  return exception.reason;
}
