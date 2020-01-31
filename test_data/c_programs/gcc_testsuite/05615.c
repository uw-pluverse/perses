


typedef _Complex float COMPLEX_FLOAT;
float real_part(COMPLEX_FLOAT a)
{
  return *(float*)(&a);
}

float real_part_2(COMPLEX_FLOAT a)
{
  return ((float*)(&a))[0];
}


float imag_part(COMPLEX_FLOAT a)
{
  return ((float*)(&a))[1];
}
