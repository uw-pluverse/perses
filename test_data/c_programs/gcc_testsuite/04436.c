





struct S
{
  volatile int i: 4;
  volatile int j: 4;
  volatile int k: 8;
  volatile int l: 8;
  volatile int m: 8;
} var;

void setit()
{
  var.j = 5;
}
