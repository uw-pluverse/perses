







void *do_it(void * dest, const void * src);
double *create_float(void);

void parse_rvalue(void **DataPtr)
{
  double local = 0.0;
  int terms = 1;

  *DataPtr = create_float();

  switch (terms)
    {
    case 1:
      *((double *)*DataPtr) = local;
      break;

    case 2:
      do_it(*DataPtr, &local);
      break;
    }
}
