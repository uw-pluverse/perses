



typedef struct FILE FILE;
int _fwalk(int (*)(FILE *));
int __sflush(FILE *);
int
fflush(FILE *fp)
{
  return (_fwalk(__sflush));
}
