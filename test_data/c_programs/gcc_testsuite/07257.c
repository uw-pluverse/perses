





extern int foo __attribute__ ((visibility ("hidden")));
int *test = &foo;
