


extern void *malloc(long unsigned int);

struct S {
  int i;
};

int main(int argc, char *argv[])
{
  int i = argc;
  struct S *p = malloc(sizeof (struct S));
  return p[i].i;
}
