






typedef void (*fp)(void);
extern char* bar(void* a1, int a2);
extern char* mar(int n);
char* cptr;

void foo()
{
  cptr = mar(6);
  ((char *(*)(void *,int (*)(void *,unsigned char **),char**))((fp)bar))(0,0,(void*)(0));
}
