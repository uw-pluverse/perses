


typedef struct {
    float a,b,c;
} S;

S * arr[100];

void bar (float *in[], int n)
{
  int i;
  for (i=0; i<n; i++)
    (*in)[i] = -arr[i]->b;
}
