


static int a=4;
static int b __attribute__ ((alias("a")));
int
main()
{
   return b+a;
}
