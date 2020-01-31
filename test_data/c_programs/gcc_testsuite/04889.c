


int x = 6;

void
foo ()
{
  int v;
 v = x;
 v = x;
 x = v;
 x = v;
 x += v;
 x += v;
 v = x += 2;
 v = x += 2;
 v = x;
 x = v;
 x += v;
 v = x += 2;
}
