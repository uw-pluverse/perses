
extern void abort (void);

extern long unsigned int strlen (const char *);
void foo(char *str)
{
  int len2 = strlen (str);
  char *a = (char *) __builtin_alloca (0);
  char *b = (char *) __builtin_alloca (len2*3);

  if ((int) (a-b) < (len2*3))
    {



      return;
    }
}

static char * volatile argp = "pr36321.x";

int main(int argc, char **argv)
{
  foo (argp);
  return 0;
}
