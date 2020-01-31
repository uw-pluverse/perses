

int *p;
int main(int argc, char **argv)
{
  int result;
  *p = 2;
  if (argc)
    *p = 2;
  result = *p;
  return result;
}
