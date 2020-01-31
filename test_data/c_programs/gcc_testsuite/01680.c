



void test_long_long_1d(int *array, int num_elems);
void test_long_long_2d(int *array, int num_rows, int num_cols);
void test_long_1d(int *array, int num_elems);
void test_int_1d(int *array, int num_elems);
void test_short_1d(int *array, int num_elems);
void test_mixed(int *array, int num_elems);

int main(int argc, char **argv)
{
  int my_array[10];
  int my_2d_array[2][3];
  int i, j;

  for(i = 0; i < 10; i++)
    my_array[i] = i;

  for(i = 0; i < 2; i++)
    for(j = 0; j < 3; j++)
      my_2d_array[i][j] = (i*3) + j;


  test_long_long_1d(my_array, 10);



  test_long_long_2d(my_2d_array[0], 3, 2);


  test_long_1d(my_array, 10);


  test_int_1d(my_array, 10);


  test_short_1d(my_array, 10);



  test_mixed(my_array, 10);

  return 0;
}
