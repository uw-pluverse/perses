



typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;


extern void abort (void);
void foo(int i, ...)
{
  __int128 q;
  va_list va;

  __builtin_va_start(va, i);
  q = __builtin_va_arg(va, __int128);
  __builtin_va_end(va);

  if (q != ((__int128) ( (((unsigned __int128) (unsigned int) 0xfeffffffU) << 96) | (((unsigned __int128) (unsigned int) 2U) << 64) | (((unsigned __int128) (unsigned int) 3U) << 32) | ((unsigned __int128) (unsigned int) 4U) )))
    abort();
}

int main(void)
{
  __int128 q = ((__int128) ( (((unsigned __int128) (unsigned int) 0xfeffffffU) << 96) | (((unsigned __int128) (unsigned int) 2U) << 64) | (((unsigned __int128) (unsigned int) 3U) << 32) | ((unsigned __int128) (unsigned int) 4U) ));

  foo(1, q);
  return 0;
}
