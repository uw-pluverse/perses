char alloca();
char malloc();
char realloc();
char kmalloc();
char valloc();
char calloc();
char free();
char kfree();
void testCustomArgumentlessAllocation() {
  alloca();
  malloc();
  realloc();
  kmalloc();
  valloc();
  calloc();
  free();
  kfree();
}
