



extern void abort (void);

struct {
        char one;
        long two;
} defaultalign;



#pragma pack(ALIGNHIGH)
struct {
        char one;
        long two;
} sixteen;


#pragma pack(ALIGN1(4))
struct {
        char one;
        long two;
} two;


#pragma pack(ALIGN2(2))
struct {
        char one;
        long two;
} three;


#pragma pack(EMPTY)
struct {
        char one;
        long two;
} resetalign;

main()
{
        if(sizeof(sixteen) < sizeof(defaultalign)) abort();
        if(sizeof(two) >= sizeof(defaultalign)) abort();
        if(sizeof(three) <= sizeof(two)) abort();
        if(sizeof(resetalign) != sizeof(defaultalign)) abort();
 return 0;
}
