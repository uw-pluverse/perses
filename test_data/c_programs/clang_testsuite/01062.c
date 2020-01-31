union either_pointer {
  void *void_ptr;
  int *int_ptr;
} __attribute__((transparent_union));
extern void foo(union either_pointer p);
int data;
void bar(void) {
  return foo(&data);
}
