



int
main (int argc, char **argv)
{

    int a[2], b[2];
    int i;

    for (i = 0; i < 2; i++)
    {
        a[i] = 3;
        b[i] = 0;
    }

{
    int ii;

    for (ii = 0; ii < 2; ii++)
    {
        const int idx = ii;
        int n = 1;
        const int len = n;



 b[ii] = a[ii];
    }
}


    for (i = 0; i < 2; i++)
    {
        if (a[i] != b[i])
            __builtin_abort ();
    }

    return 0;
}
