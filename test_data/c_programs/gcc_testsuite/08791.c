



struct a {int a,b,c;} a;
int test(struct a a)
{
struct a nasty_local;
__builtin_memcpy (&nasty_local,&a, sizeof(a));
return nasty_local.a;
}
