typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
va_list the_list;
int simple_int(void) {
  return __builtin_va_arg(the_list,int);
}
__int128 aligned_int(void) {
  return __builtin_va_arg(the_list,__int128);
}
struct bigstruct {
  int a[10];
};
struct bigstruct simple_indirect(void) {
  return __builtin_va_arg(the_list,struct bigstruct);
}
struct aligned_bigstruct {
  float a;
  long double b;
};
struct aligned_bigstruct simple_aligned_indirect(void) {
  return __builtin_va_arg(the_list,struct aligned_bigstruct);
}
double simple_double(void) {
  return __builtin_va_arg(the_list,double);
}
struct hfa {
  float a, b;
};
struct hfa simple_hfa(void) {
  return __builtin_va_arg(the_list,struct hfa);
}
void check_start(int n, ...) {
  va_list the_list;
  __builtin_va_start(the_list,n);
}
