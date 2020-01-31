




struct foo
{
    int i;
};

int bar (void)
{
    return ((struct foo *)0x1234)->i;
}
