

static const int __attribute__ ((used)) cst_local = 4;
static int __attribute__ ((used)) glob_local = 5;
const int __attribute__ ((used)) cst_export = 4;
int __attribute__ ((used)) glob_export = 5;
extern const int cst_import;
extern int glob_import;

int Foo ()
{
  return cst_import + glob_import;
}
