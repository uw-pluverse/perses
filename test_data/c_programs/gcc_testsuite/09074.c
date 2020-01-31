







__thread int a_thread_local;
void *
spin (int n)
{
  int i;
  for (i = 0; i <= n; i++)
    {
      a_thread_local += i;
    }
}
