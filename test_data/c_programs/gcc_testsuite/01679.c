




void test_scalar(_Bool *my_c_bool_ptr);
void test_array(_Bool *my_bool_array, int num_elems);

int main(int argc, char **argv)
{
  _Bool my_bool = 1;
  _Bool my_bool_array[10];
  int i;

  test_scalar(&my_bool);

  for(i = 0; i < 10; i+=2)
    my_bool_array[i] = 1;
  for(i = 1; i < 10; i+=2)
    my_bool_array[i] = 0;

  test_array(my_bool_array, 10);

  return 0;
}
