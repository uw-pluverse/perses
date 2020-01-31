


unsigned int a, *b;
unsigned short c;
int d;

void
fn1 ()
{
  b = &d;
  *b = c = a;
  *b = d;
}
