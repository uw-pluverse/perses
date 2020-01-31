extern int global_var;
void foo_func(int param1);
void bar_func(void);
struct MyStruct {
  int field_var;
};
int global_var = 10;
void bar_func(void) {
  global_var += 100;
  foo_func(global_var);
  struct MyStruct *ms;
  ms->field_var = 10;
}
