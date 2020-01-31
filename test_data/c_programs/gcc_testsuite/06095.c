





void
quantum_toffoli (int control1, int control2, int target,
   unsigned long *state, int size)
{
  int i;

  for(i=0; i<size; i++)
    {
       if (state[i] & ((unsigned long) 1 << control1))
         if (state[i] & ((unsigned long) 1 << control2))
           state[i] ^= ((unsigned long) 1 << target);
    }
}
