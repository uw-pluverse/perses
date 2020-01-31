


struct { int a, b; } soup1, soup2;
void
foo ()
{
  soup1 = soup2;
  soup1.a = 66;
  soup1.b = 77;
}
