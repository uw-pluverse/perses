typedef double gdouble;
void focus_changed_cb () {
    __builtin_va_list pa;
    double mfloat;
    mfloat = __builtin_va_arg((pa), gdouble);
}
void vararg(int, ...);
void function_as_vararg() {
  vararg(0, focus_changed_cb);
}
void vla(int n, ...)
{
  __builtin_va_list ap;
  void *p;
  p = __builtin_va_arg(ap, typeof (int (*)[++n]));
}
