





void __lock_get_list(void *dp)
{
  if (((long unsigned int)dp + 1) & ~1ULL)
    ;
}
