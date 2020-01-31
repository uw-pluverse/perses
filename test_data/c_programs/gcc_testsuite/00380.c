char
char_fetch_add_relaxed (char *ptr, int value)
{
  return __atomic_fetch_add (ptr, value, 0);
}

char
char_fetch_sub_consume (char *ptr, int value)
{
  return __atomic_fetch_sub (ptr, value, 1);
}

char
char_fetch_and_acquire (char *ptr, int value)
{
  return __atomic_fetch_and (ptr, value, 2);
}

char
char_fetch_ior_release (char *ptr, int value)
{
  return __atomic_fetch_or (ptr, value, 3);
}

char
char_fetch_xor_acq_rel (char *ptr, int value)
{
  return __atomic_fetch_xor (ptr, value, 4);
}

char
char_fetch_nand_seq_cst (char *ptr, int value)
{
  return __atomic_fetch_nand (ptr, value, 5);
}


short
short_fetch_add_relaxed (short *ptr, int value)
{
  return __atomic_fetch_add (ptr, value, 0);
}

short
short_fetch_sub_consume (short *ptr, int value)
{
  return __atomic_fetch_sub (ptr, value, 1);
}

short
short_fetch_and_acquire (short *ptr, int value)
{
  return __atomic_fetch_and (ptr, value, 2);
}

short
short_fetch_ior_release (short *ptr, int value)
{
  return __atomic_fetch_or (ptr, value, 3);
}

short
short_fetch_xor_acq_rel (short *ptr, int value)
{
  return __atomic_fetch_xor (ptr, value, 4);
}

short
short_fetch_nand_seq_cst (short *ptr, int value)
{
  return __atomic_fetch_nand (ptr, value, 5);
}


int
int_fetch_add_relaxed (int *ptr, int value)
{
  return __atomic_fetch_add (ptr, value, 0);
}

int
int_fetch_sub_consume (int *ptr, int value)
{
  return __atomic_fetch_sub (ptr, value, 1);
}

int
int_fetch_and_acquire (int *ptr, int value)
{
  return __atomic_fetch_and (ptr, value, 2);
}

int
int_fetch_ior_release (int *ptr, int value)
{
  return __atomic_fetch_or (ptr, value, 3);
}

int
int_fetch_xor_acq_rel (int *ptr, int value)
{
  return __atomic_fetch_xor (ptr, value, 4);
}

int
int_fetch_nand_seq_cst (int *ptr, int value)
{
  return __atomic_fetch_nand (ptr, value, 5);
}


long
long_fetch_add_relaxed (long *ptr, long value)
{
  return __atomic_fetch_add (ptr, value, 0);
}

long
long_fetch_sub_consume (long *ptr, long value)
{
  return __atomic_fetch_sub (ptr, value, 1);
}

long
long_fetch_and_acquire (long *ptr, long value)
{
  return __atomic_fetch_and (ptr, value, 2);
}

long
long_fetch_ior_release (long *ptr, long value)
{
  return __atomic_fetch_or (ptr, value, 3);
}

long
long_fetch_xor_acq_rel (long *ptr, long value)
{
  return __atomic_fetch_xor (ptr, value, 4);
}

long
long_fetch_nand_seq_cst (long *ptr, long value)
{
  return __atomic_fetch_nand (ptr, value, 5);
}


__int128_t
quad_fetch_add_relaxed (__int128_t *ptr, __int128_t value)
{
  return __atomic_fetch_add (ptr, value, 0);
}

__int128_t
quad_fetch_sub_consume (__int128_t *ptr, __int128_t value)
{
  return __atomic_fetch_sub (ptr, value, 1);
}

__int128_t
quad_fetch_and_acquire (__int128_t *ptr, __int128_t value)
{
  return __atomic_fetch_and (ptr, value, 2);
}

__int128_t
quad_fetch_ior_release (__int128_t *ptr, __int128_t value)
{
  return __atomic_fetch_or (ptr, value, 3);
}

__int128_t
quad_fetch_xor_acq_rel (__int128_t *ptr, __int128_t value)
{
  return __atomic_fetch_xor (ptr, value, 4);
}

__int128_t
quad_fetch_nand_seq_cst (__int128_t *ptr, __int128_t value)
{
  return __atomic_fetch_nand (ptr, value, 5);
}
