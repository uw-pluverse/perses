





__attribute__((target_clones("arch=core-avx2","arch=slm","default")))
void
foo(char *in, char *out, int size)
{
  int i;
  for(i = 0; i < size; i++)
    {
 out[2 * i] = in[i];
 out[2 * i + 1] = in[i];
    }
}
