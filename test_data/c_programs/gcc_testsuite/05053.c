

static struct a {int magic1,b;} a;
volatile int magic2;
static struct b {int a,b,c,d,e,f;} magic3;

struct b foo();

void
t()
{
 a.magic1 = 1;
 magic2 = 1;
 magic3 = foo();
}
