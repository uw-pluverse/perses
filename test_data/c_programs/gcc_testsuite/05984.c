


struct abc {
    void (*abc_call)(void);
};
static inline int do_register(struct abc *xyz)
{
    return 0;
}




static void call_func(void)
{
}

static struct abc xyz = {
    .abc_call = call_func,
};

void func(void)
{
    do_register(&xyz);
}
