


struct struct_t
{
  int* data;
};

void foo (struct struct_t* sp, int start, int end)
{
  int i;

  for (i = 0; i+start < end; i++)
    sp->data[i+start] = 0;
}
