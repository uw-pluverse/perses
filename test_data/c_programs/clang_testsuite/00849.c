typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
int get_int(va_list *args) {
  return __builtin_va_arg(*args,int);
}
struct Foo {
  int x;
};
struct Foo dest;
void get_struct(va_list *args) {
 dest = __builtin_va_arg(*args,struct Foo);
}
enum E { Foo_one = 1 };
enum E enum_dest;
void get_enum(va_list *args) {
  enum_dest = __builtin_va_arg(*args,enum E);
}
