



void set(void*);

int foo(int argc)
{
  volatile double val;
  set((void*)&val);
}
