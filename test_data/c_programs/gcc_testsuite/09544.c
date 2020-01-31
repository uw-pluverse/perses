






extern void abort(void);

int v, count, res;
const int init = ~0;



void
test_fetch_add ()
{
  v = 0;
  count = 1;

  if (__atomic_fetch_add (&v, count, 0) != 0)
    abort ();

  if (__atomic_fetch_add (&v, 1, 1) != 1)
    abort ();

  if (__atomic_fetch_add (&v, count, 2) != 2)
    abort ();

  if (__atomic_fetch_add (&v, 1, 3) != 3)
    abort ();

  if (__atomic_fetch_add (&v, count, 4) != 4)
    abort ();

  if (__atomic_fetch_add (&v, 1, 5) != 5)
    abort ();
}


void
test_fetch_sub()
{
  v = res = 20;
  count = 0;

  if (__atomic_fetch_sub (&v, count + 1, 0) != res--)
    abort ();

  if (__atomic_fetch_sub (&v, 1, 1) != res--)
    abort ();

  if (__atomic_fetch_sub (&v, count + 1, 2) != res--)
    abort ();

  if (__atomic_fetch_sub (&v, 1, 3) != res--)
    abort ();

  if (__atomic_fetch_sub (&v, count + 1, 4) != res--)
    abort ();

  if (__atomic_fetch_sub (&v, 1, 5) != res--)
    abort ();
}

void
test_fetch_and ()
{
  v = init;

  if (__atomic_fetch_and (&v, 0, 0) != init)
    abort ();

  if (__atomic_fetch_and (&v, init, 1) != 0)
    abort ();

  if (__atomic_fetch_and (&v, 0, 2) != 0)
    abort ();

  v = ~v;
  if (__atomic_fetch_and (&v, init, 3) != init)
    abort ();

  if (__atomic_fetch_and (&v, 0, 4) != init)
    abort ();

  if (__atomic_fetch_and (&v, 0, 5) != 0)
    abort ();
}

void
test_fetch_nand ()
{
  v = init;

  if (__atomic_fetch_nand (&v, 0, 0) != init)
    abort ();

  if (__atomic_fetch_nand (&v, init, 1) != init)
    abort ();

  if (__atomic_fetch_nand (&v, 0, 2) != 0 )
    abort ();

  if (__atomic_fetch_nand (&v, init, 3) != init)
    abort ();

  if (__atomic_fetch_nand (&v, init, 4) != 0)
    abort ();

  if (__atomic_fetch_nand (&v, 0, 5) != init)
    abort ();
}

void
test_fetch_xor ()
{
  v = init;
  count = 0;

  if (__atomic_fetch_xor (&v, count, 0) != init)
    abort ();

  if (__atomic_fetch_xor (&v, ~count, 1) != init)
    abort ();

  if (__atomic_fetch_xor (&v, 0, 2) != 0)
    abort ();

  if (__atomic_fetch_xor (&v, ~count, 3) != 0)
    abort ();

  if (__atomic_fetch_xor (&v, 0, 4) != init)
    abort ();

  if (__atomic_fetch_xor (&v, ~count, 5) != init)
    abort ();
}

void
test_fetch_or ()
{
  v = 0;
  count = 1;

  if (__atomic_fetch_or (&v, count, 0) != 0)
    abort ();

  count *= 2;
  if (__atomic_fetch_or (&v, 2, 1) != 1)
    abort ();

  count *= 2;
  if (__atomic_fetch_or (&v, count, 2) != 3)
    abort ();

  count *= 2;
  if (__atomic_fetch_or (&v, 8, 3) != 7)
    abort ();

  count *= 2;
  if (__atomic_fetch_or (&v, count, 4) != 15)
    abort ();

  count *= 2;
  if (__atomic_fetch_or (&v, count, 5) != 31)
    abort ();
}



void
test_add_fetch ()
{
  v = 0;
  count = 1;

  if (__atomic_add_fetch (&v, count, 0) != 1)
    abort ();

  if (__atomic_add_fetch (&v, 1, 1) != 2)
    abort ();

  if (__atomic_add_fetch (&v, count, 2) != 3)
    abort ();

  if (__atomic_add_fetch (&v, 1, 3) != 4)
    abort ();

  if (__atomic_add_fetch (&v, count, 4) != 5)
    abort ();

  if (__atomic_add_fetch (&v, count, 5) != 6)
    abort ();
}


void
test_sub_fetch ()
{
  v = res = 20;
  count = 0;

  if (__atomic_sub_fetch (&v, count + 1, 0) != --res)
    abort ();

  if (__atomic_sub_fetch (&v, 1, 1) != --res)
    abort ();

  if (__atomic_sub_fetch (&v, count + 1, 2) != --res)
    abort ();

  if (__atomic_sub_fetch (&v, 1, 3) != --res)
    abort ();

  if (__atomic_sub_fetch (&v, count + 1, 4) != --res)
    abort ();

  if (__atomic_sub_fetch (&v, count + 1, 5) != --res)
    abort ();
}

void
test_and_fetch ()
{
  v = init;

  if (__atomic_and_fetch (&v, 0, 0) != 0)
    abort ();

  v = init;
  if (__atomic_and_fetch (&v, init, 1) != init)
    abort ();

  if (__atomic_and_fetch (&v, 0, 2) != 0)
    abort ();

  v = ~v;
  if (__atomic_and_fetch (&v, init, 3) != init)
    abort ();

  if (__atomic_and_fetch (&v, 0, 4) != 0)
    abort ();

  v = ~v;
  if (__atomic_and_fetch (&v, 0, 5) != 0)
    abort ();
}

void
test_nand_fetch ()
{
  v = init;

  if (__atomic_nand_fetch (&v, 0, 0) != init)
    abort ();

  if (__atomic_nand_fetch (&v, init, 1) != 0)
    abort ();

  if (__atomic_nand_fetch (&v, 0, 2) != init)
    abort ();

  if (__atomic_nand_fetch (&v, init, 3) != 0)
    abort ();

  if (__atomic_nand_fetch (&v, init, 4) != init)
    abort ();

  if (__atomic_nand_fetch (&v, 0, 5) != init)
    abort ();
}



void
test_xor_fetch ()
{
  v = init;
  count = 0;

  if (__atomic_xor_fetch (&v, count, 0) != init)
    abort ();

  if (__atomic_xor_fetch (&v, ~count, 1) != 0)
    abort ();

  if (__atomic_xor_fetch (&v, 0, 2) != 0)
    abort ();

  if (__atomic_xor_fetch (&v, ~count, 3) != init)
    abort ();

  if (__atomic_xor_fetch (&v, 0, 4) != init)
    abort ();

  if (__atomic_xor_fetch (&v, ~count, 5) != 0)
    abort ();
}

void
test_or_fetch ()
{
  v = 0;
  count = 1;

  if (__atomic_or_fetch (&v, count, 0) != 1)
    abort ();

  count *= 2;
  if (__atomic_or_fetch (&v, 2, 1) != 3)
    abort ();

  count *= 2;
  if (__atomic_or_fetch (&v, count, 2) != 7)
    abort ();

  count *= 2;
  if (__atomic_or_fetch (&v, 8, 3) != 15)
    abort ();

  count *= 2;
  if (__atomic_or_fetch (&v, count, 4) != 31)
    abort ();

  count *= 2;
  if (__atomic_or_fetch (&v, count, 5) != 63)
    abort ();
}





void
test_add ()
{
  v = 0;
  count = 1;

  __atomic_add_fetch (&v, count, 0);
  if (v != 1)
    abort ();

  __atomic_fetch_add (&v, count, 1);
  if (v != 2)
    abort ();

  __atomic_add_fetch (&v, 1 , 2);
  if (v != 3)
    abort ();

  __atomic_fetch_add (&v, 1, 3);
  if (v != 4)
    abort ();

  __atomic_add_fetch (&v, count, 4);
  if (v != 5)
    abort ();

  __atomic_fetch_add (&v, count, 5);
  if (v != 6)
    abort ();
}


void
test_sub()
{
  v = res = 20;
  count = 0;

  __atomic_sub_fetch (&v, count + 1, 0);
  if (v != --res)
    abort ();

  __atomic_fetch_sub (&v, count + 1, 1);
  if (v != --res)
    abort ();

  __atomic_sub_fetch (&v, 1, 2);
  if (v != --res)
    abort ();

  __atomic_fetch_sub (&v, 1, 3);
  if (v != --res)
    abort ();

  __atomic_sub_fetch (&v, count + 1, 4);
  if (v != --res)
    abort ();

  __atomic_fetch_sub (&v, count + 1, 5);
  if (v != --res)
    abort ();
}

void
test_and ()
{
  v = init;

  __atomic_and_fetch (&v, 0, 0);
  if (v != 0)
    abort ();

  v = init;
  __atomic_fetch_and (&v, init, 1);
  if (v != init)
    abort ();

  __atomic_and_fetch (&v, 0, 2);
  if (v != 0)
    abort ();

  v = ~v;
  __atomic_fetch_and (&v, init, 3);
  if (v != init)
    abort ();

  __atomic_and_fetch (&v, 0, 4);
  if (v != 0)
    abort ();

  v = ~v;
  __atomic_fetch_and (&v, 0, 5);
  if (v != 0)
    abort ();
}

void
test_nand ()
{
  v = init;

  __atomic_fetch_nand (&v, 0, 0);
  if (v != init)
    abort ();

  __atomic_fetch_nand (&v, init, 1);
  if (v != 0)
    abort ();

  __atomic_nand_fetch (&v, 0, 2);
  if (v != init)
    abort ();

  __atomic_nand_fetch (&v, init, 3);
  if (v != 0)
    abort ();

  __atomic_fetch_nand (&v, init, 4);
  if (v != init)
    abort ();

  __atomic_nand_fetch (&v, 0, 5);
  if (v != init)
    abort ();
}



void
test_xor ()
{
  v = init;
  count = 0;

  __atomic_xor_fetch (&v, count, 0);
  if (v != init)
    abort ();

  __atomic_fetch_xor (&v, ~count, 1);
  if (v != 0)
    abort ();

  __atomic_xor_fetch (&v, 0, 2);
  if (v != 0)
    abort ();

  __atomic_fetch_xor (&v, ~count, 3);
  if (v != init)
    abort ();

  __atomic_fetch_xor (&v, 0, 4);
  if (v != init)
    abort ();

  __atomic_xor_fetch (&v, ~count, 5);
  if (v != 0)
    abort ();
}

void
test_or ()
{
  v = 0;
  count = 1;

  __atomic_or_fetch (&v, count, 0);
  if (v != 1)
    abort ();

  count *= 2;
  __atomic_fetch_or (&v, count, 1);
  if (v != 3)
    abort ();

  count *= 2;
  __atomic_or_fetch (&v, 4, 2);
  if (v != 7)
    abort ();

  count *= 2;
  __atomic_fetch_or (&v, 8, 3);
  if (v != 15)
    abort ();

  count *= 2;
  __atomic_or_fetch (&v, count, 4);
  if (v != 31)
    abort ();

  count *= 2;
  __atomic_fetch_or (&v, count, 5);
  if (v != 63)
    abort ();
}

int
main ()
{
  test_fetch_add ();
  test_fetch_sub ();
  test_fetch_and ();
  test_fetch_nand ();
  test_fetch_xor ();
  test_fetch_or ();

  test_add_fetch ();
  test_sub_fetch ();
  test_and_fetch ();
  test_nand_fetch ();
  test_xor_fetch ();
  test_or_fetch ();

  test_add ();
  test_sub ();
  test_and ();
  test_nand ();
  test_xor ();
  test_or ();

  return 0;
}
