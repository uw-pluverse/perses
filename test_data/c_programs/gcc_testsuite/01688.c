double fabs (double);

typedef struct ctype
{
  int i;
  double x;
}ctype_t;

int test_scalar_address(int *ptr)
{

  if(*ptr != 100)
    return 0;
  else
    return 1;
}

int test_array_address(int *int_array, int num_elements)
{
  int i = 0;

  for(i = 0; i < num_elements; i++)

    if(int_array[i] != 100)
      return 0;


  return 1;
}

int test_type_address(ctype_t *type_ptr)
{

  if(type_ptr->i != 100)
    return 0;


  if(fabs(type_ptr->x - 1.0) > 0.00000000)
    return 0;

  return 1;
}
