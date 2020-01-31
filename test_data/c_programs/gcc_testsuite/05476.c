

int foo(double* p, double* q)
{
    int i=0;

    for (; q!=p; ++q)
        if (*q)
            ++i;

    return i;
}
