extern void *memset (void *, int, long unsigned int);
extern void abort (void);

static void foo ()
{
    char a[15000];

    a[0]=0;
    memset( &a[0], 0xCD, 13371 );
    a[13371]=0;
    if (strlen(a) != 13371)
      abort ();
}

int main ( int argc, char* argv[] )
{
    foo();
    return 0;
}
