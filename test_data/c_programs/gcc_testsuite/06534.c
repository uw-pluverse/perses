

extern void *memmove(void *, void *, long unsigned int);
typedef int (*_TEST_fun_) ();
static _TEST_fun_ i = (_TEST_fun_) memmove;
int main() { i(); }
