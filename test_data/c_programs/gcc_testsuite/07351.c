




char ** _M_allocate();
void
_M_fill_insert(unsigned int __n)
{
   char **__new_start = _M_allocate();
   char *__tmp = 0;
   for (; __n > 0; --__n, ++__new_start)
     *__new_start = __tmp;
}
