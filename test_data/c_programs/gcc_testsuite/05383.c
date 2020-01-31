


int main(int argc, char* argv[])
{
  int i, a = 0;
  for (i=0; i < 10; i++)
    a += i + 0xff00ff;
  return a;
}
