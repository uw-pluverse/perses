








void
foo (void *TM_buff, long *result, unsigned char *code)
{
  *result++ = __TM_simple_begin ();
  *result++ = __TM_begin (TM_buff);
  *result++ = __TM_end ();
  __TM_abort ();
  __TM_named_abort (*code);
  __TM_resume ();
  __TM_suspend ();
  *result++ = __TM_is_user_abort (TM_buff);
  *result++ = __TM_is_named_user_abort (TM_buff, code);
  *result++ = __TM_is_illegal (TM_buff);
  *result++ = __TM_is_footprint_exceeded (TM_buff);
  *result++ = __TM_nesting_depth (TM_buff);
  *result++ = __TM_is_nested_too_deep (TM_buff);
  *result++ = __TM_is_conflict (TM_buff);
  *result++ = __TM_is_failure_persistent (TM_buff);
  *result++ = __TM_failure_address (TM_buff);
  *result++ = __TM_failure_code (TM_buff);
}
