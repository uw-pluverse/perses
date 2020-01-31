



static int i;
extern int j __attribute__ ((alias ("i")));
int *p = &j;
