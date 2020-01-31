__int128
atomic_load_128_relaxed (__int128 *ptr)
{
 return __atomic_load_n (ptr, 0);
}

void
atomic_store_128_relaxed (__int128 *ptr, __int128 val)
{
 __atomic_store_n (ptr, val, 0);
}
