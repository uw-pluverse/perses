extern int _foo(void);
extern int _foo64(void);
#pragma redefine_extname foo64 foo
int
bar()
{
        return (_foo64());
}
