




int dummy1[sizeof(_Bool)];
int dummy2[2 - sizeof(_Bool)];

int main()
{
  return sizeof(_Bool) == 1 ? 0 : 1;
}
