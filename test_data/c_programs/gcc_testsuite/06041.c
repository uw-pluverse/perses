typedef struct
{
    char chars[5];
}
baz_t;

extern baz_t * baz;

extern void foo (baz_t);
int
bar (const baz_t * ls)
{
    foo (ls == 0 ? *(&baz[0]) : *ls);
}
