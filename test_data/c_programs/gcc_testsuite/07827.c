


struct Atomics
{
  _Atomic(int) counter;
  struct Pointer
  {
    _Atomic volatile char *p;
  } p;
};

struct Atomics a;
