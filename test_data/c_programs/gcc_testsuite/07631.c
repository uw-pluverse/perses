



__int128_t i;

int main()
{
  __atomic_store_16(&i, -1, 0);
  if (i != -1)
    __builtin_abort();
  return 0;
}
