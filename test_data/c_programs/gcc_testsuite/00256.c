


struct f
{
  long long ll;
  int i;
};

int f[sizeof(struct f)!=16?-1:1];
