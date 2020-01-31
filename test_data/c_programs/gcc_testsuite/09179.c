






enum e { A, B };

enum e ev;
unsigned char uv;
enum e *ep = &uv;
unsigned char *up = &ev;

int i;
__typeof__(A) te;
int *ip = &te;
__typeof__(B) *tep = &i;

int x[((sizeof(A) == sizeof(int)) ? 1 : -1)];
