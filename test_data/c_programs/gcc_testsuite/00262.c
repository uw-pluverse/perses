



extern int externvar;
extern void externfunc(void);

int *localvar = &externvar;
void (*localfunc)(void) = externfunc;
