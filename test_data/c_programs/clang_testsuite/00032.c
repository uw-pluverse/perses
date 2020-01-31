char memmove ();
char malloc();
char system();
char stdin();
char memccpy();
char free();
char strdup();
char atoi();
int foo () {
  return memmove() + malloc() + system() + stdin() + memccpy() + free() + strdup() + atoi();
}
