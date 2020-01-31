








int main(){
  volatile float f = 1.40129846e-45F;
  volatile double d = 4.9406564584124654e-324;
  volatile long double l = 3.64519953188247460253e-4951L;
  if (f == 0 || d == 0 || l == 0)
    __builtin_abort ();
  return 0;
}
