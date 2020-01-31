






float f0(__attribute__((vector_size(16))) float t)
{
  return ((float*)&t)[0];
}

float f1(__attribute__((vector_size(16))) float t)
{
  return ((float*)&t)[1];
}

float f2(__attribute__((vector_size(16))) float t)
{
  return ((float*)&t)[2];
}

float f3(__attribute__((vector_size(16))) float t)
{
  return ((float*)&t)[3];
}
