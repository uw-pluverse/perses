



int (*indirect_func)(int x);

int indirect_call()
{
  return indirect_func(20) + indirect_func (40);
}
