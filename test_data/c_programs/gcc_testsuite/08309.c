




extern void abort(void);

int v, count;


int
main ()
{
  v = 0;
  count = 0;

  if (__atomic_load_n (&v, 0) != count++)
    abort();
  else
    v++;

  if (__atomic_load_n (&v, 2) != count++)
    abort();
  else
    v++;

  if (__atomic_load_n (&v, 1) != count++)
    abort();
  else
    v++;

  if (__atomic_load_n (&v, 5) != count++)
    abort();
  else
    v++;



  __atomic_load (&v, &count, 0);
  if (count != v)
    abort();
  else
    v++;

  __atomic_load (&v, &count, 2);
  if (count != v)
    abort();
  else
    v++;

  __atomic_load (&v, &count, 1);
  if (count != v)
    abort();
  else
    v++;

  __atomic_load (&v, &count, 5);
  if (count != v)
    abort();
  else
    v++;


  return 0;
}
