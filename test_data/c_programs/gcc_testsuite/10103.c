#pragma weak a
int a;

int b;
#pragma weak b

#pragma weak c
extern int c;
int c;

extern int d;
#pragma weak d
int d;

#pragma weak e
void e(void) { }







#pragma weak g
int g = 1;







#pragma weak i
extern int i;

#pragma weak j
extern int j;
int use_j() { return j; }
