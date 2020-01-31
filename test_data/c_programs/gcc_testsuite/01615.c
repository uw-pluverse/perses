

extern int foo () __attribute__((version_id ("20040821")));

int bar(int i)
{
 return (foo() + 1);
}
