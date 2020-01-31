





struct array
{
  char align[4092];
  long long elem[2] __attribute__ ((__packed__));
};

long long
test (struct array *array, int i)
{
  return array->elem[i];
}
