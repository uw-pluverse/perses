




int a1[256], a2[256], a3[256], a4[256];

void foo ()
{
  int i;
  for (i=0; i<256; i++) {
    int c;
    c = a3[i] + (a1[i] * a2[i]);
    a4[i] = c + 1;
    a1[i] = a2[i] - 1;
  }
}
