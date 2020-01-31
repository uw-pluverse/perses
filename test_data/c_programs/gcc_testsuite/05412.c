





void
quantum_toffoli(int control1, int control2, int target, int *state,
int size)
{
  int i;

  for(i=0; i<size; i++)
    {
       if (state[i] & ( 1 << control1))
         if (state[i] & ( 1 << control2))
           state[i] ^= ( 1 << target);
    }
}
