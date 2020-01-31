





__int128
quad_exchange (__int128 *ptr, __int128 newval)
{
  return __atomic_exchange_n (ptr, newval, 0);
}
