




typedef int __attribute__((vector_size(16))) v4si;
typedef int __attribute__((vector_size(8))) v2si;

v4si
f(v4si v)
{
    return v;
}

v2si
g(v2si v)
{
    return v;
}

int
main()
{
    v4si v = { 1, 2, 3, 4 };
    v2si w = { 5, 6 };
    v = f (v);
    w = g (w);
    return 0;
}
