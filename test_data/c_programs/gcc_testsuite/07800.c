



__attribute__ ((used))
static char i_outer;
struct {
   char f1;
   char f2;
} opta;
struct {
   char f1;
   char f2;
} optb;

int
main()
{
   static char i_inner[2] __attribute__ ((used));
   i_inner[0] = 'a'; i_inner[1] = 'b';
   opta.f1 = 'c';
   opta.f2 = 'd';
   optb.f1 = 'C';
   optb.f2 = 'D';
   i_outer = 'e';



   return 0;
}
