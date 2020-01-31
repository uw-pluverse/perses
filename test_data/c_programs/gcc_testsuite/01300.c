





struct backtrace_state
{
  int threaded;
  int lock_alloc;
};

void foo (struct backtrace_state *state)
{
  if (state->threaded)
    __sync_lock_release (&state->lock_alloc);
}
