




int *p;
_Static_assert (__atomic_always_lock_free (1, p), "");
_Static_assert (__atomic_always_lock_free (1, 0), "");
