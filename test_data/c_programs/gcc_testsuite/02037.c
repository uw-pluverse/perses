extern int printf (const char *,...);

struct s { struct s *n; } *p;
struct s ss;

struct s sss[10];
int count = 0;

void sub( struct s *p, struct s **pp );
int look( struct s *p, struct s **pp );

main()
{
    struct s *pp;
    struct s *next;
    int i;

    p = &ss;
    next = p;
    for ( i = 0; i < 10; i++ ) {
        next->n = &sss[i];
        next = next->n;
    }
    next->n = 0;

    sub( p, &pp );
    if (count != 10 +2)
      abort ();

    exit( 0 );
}

void sub( struct s *p, struct s **pp )
{
   for ( ; look( p, pp ); ) {
        if ( p )
            p = p->n;
        else
            break;
   }
}

int look( struct s *p, struct s **pp )
{
    for ( ; p; p = p->n )
        ;
    *pp = p;
    count++;
    return( 1 );
}
