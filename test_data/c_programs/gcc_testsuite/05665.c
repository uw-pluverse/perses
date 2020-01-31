


typedef struct _s {
    int a;
    int b;
    int c;
    int d;
} s;

extern void g(s*);
extern void f(void);

void test_signed_msg_encoding(void)
{
    s signInfo = { sizeof(signInfo), 0 };

    signInfo.b = 1;
    signInfo.c = 0;
    g(&signInfo);
    signInfo.d = 0;
    f();
}
