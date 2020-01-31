







int
main ()
{
  __atomic_thread_fence (0);
  __atomic_thread_fence (1);
  __atomic_thread_fence (2);
  __atomic_thread_fence (3);
  __atomic_thread_fence (4);
  __atomic_thread_fence (5);

  __atomic_signal_fence (0);
  __atomic_signal_fence (1);
  __atomic_signal_fence (2);
  __atomic_signal_fence (3);
  __atomic_signal_fence (4);
  __atomic_signal_fence (5);

  return 0;
}
