






int ib[32] = {0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45};
float fa[32];
int ia[32];

int convert()
{
  int i;


  for (i = 0; i < 32; i++)
    fa[i] = (float) ib[i];


  for (i = 0; i < 32; i++)
    ia[i] = (int) fa[i];

  return 0;
}
