



struct foo s;
volatile struct foo t;
struct foo { const int z; };

void
bar (void)
{
  t = s;
}
