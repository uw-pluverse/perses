





void f1()
{

  typedef int __attribute__ ((__mode__ (__QI__))) qi_int_type;
  qi_int_type qi_int;
  __sync_bool_compare_and_swap (&qi_int, (qi_int_type)0, (qi_int_type)1);

}

void f2()
{

  typedef int __attribute__ ((__mode__ (__HI__))) hi_int_type;
  hi_int_type hi_int;
  __sync_bool_compare_and_swap (&hi_int, (hi_int_type)0, (hi_int_type)1);

}

void f4()
{

  typedef int __attribute__ ((__mode__ (__SI__))) si_int_type;
  si_int_type si_int;
  __sync_bool_compare_and_swap (&si_int, (si_int_type)0, (si_int_type)1);

}

void f8()
{

  typedef int __attribute__ ((__mode__ (__DI__))) di_int_type;
  di_int_type di_int;
  __sync_bool_compare_and_swap (&di_int, (di_int_type)0, (di_int_type)1);

}



void f16()
{





}

int main()
{
  f1();
  f2();
  f4();
  f8();
  f16();
  return 0;
}
