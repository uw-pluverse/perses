

extern int sched_yield (void);
static volatile int serial = 0;

__attribute__((no_sanitize_thread))
void step (int i)
{
   while (__atomic_load_n (&serial, 2) != i - 1)
     sched_yield ();
   __atomic_store_n (&serial, i, 3);
}
