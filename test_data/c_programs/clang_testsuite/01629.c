typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
char *foo = "test";
int test(char*,...);
int test(fmt)
        char*fmt;
{
        va_list ap;
        char*a;
        int x;
        __builtin_va_start(ap,fmt);
        a=__builtin_va_arg(ap,char*);
        x=(a!=foo);
        __builtin_va_end(ap);
        return x;
}
void exit();
int main(argc,argv)
        int argc;char**argv;
{
        exit(test("",foo));
}
