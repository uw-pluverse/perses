typedef int unary_int_func(int arg);
unary_int_func *func;
unary_int_func *set_func(void *p) {
 func = p;
 p = func;
 return p;
}
