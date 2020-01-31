
extern int __attribute__((weak)) decl;
int __attribute__((weak)) defn;

int Foo ()
{
  return decl + defn;
}
