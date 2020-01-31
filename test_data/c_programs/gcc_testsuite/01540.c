

int __attribute__ ((common)) common;
static int local;
extern int external_decl;
int external_defn;

int foo ()
{
  return common + local + external_decl + external_defn;
}

void bar (int i)
{
  common = local = external_decl = external_defn = i;
}
