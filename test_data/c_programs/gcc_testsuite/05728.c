







void foo(int* p)
{
    int i;
    for (i=1; i>0; --i, ++p)
        *p=0;
}

void bar(int* p) { foo(p); }
