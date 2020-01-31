



static __attribute__((vector_size(sizeof(int)*4) )) int allones = {1, 1, 1, 1};
static __attribute__((vector_size(sizeof(int)*4) )) int allzeros = {0, 0, 0, 0};
static __attribute__((vector_size(sizeof(int)*4) )) int numbers = {0, 1, 2, 3};
static __attribute__((vector_size(sizeof(int)*4) )) int numbersleftshiftallones = {0, 2, 4, 6};
static __attribute__((vector_size(sizeof(int)*4) )) int numbersrightshiftallones = {0, 0, 1, 1};


static __attribute__((vector_size(sizeof(int)*4) )) unsigned int uallones = {1, 1, 1, 1};
static __attribute__((vector_size(sizeof(int)*4) )) unsigned int uallzeros = {0, 0, 0, 0};
static __attribute__((vector_size(sizeof(int)*4) )) unsigned int unumbers = {0, 1, 2, 3};
static __attribute__((vector_size(sizeof(int)*4) )) unsigned int unumbersleftshiftallones = {0, 2, 4, 6};
static __attribute__((vector_size(sizeof(int)*4) )) unsigned int unumbersrightshiftallones = {0, 0, 1, 1};
int main(void)
{
  __attribute__((vector_size(sizeof(int)*4) )) int result;
  do { __typeof__((numbers << allzeros)) result1 = (numbers << allzeros); if(sizeof (result1) != sizeof (numbers)) __builtin_abort (); if (__builtin_memcmp (&result1, &numbers, sizeof(result1)) != 0) __builtin_abort (); }while (0);;
  do { __typeof__((numbers >> allzeros)) result1 = (numbers >> allzeros); if(sizeof (result1) != sizeof (numbers)) __builtin_abort (); if (__builtin_memcmp (&result1, &numbers, sizeof(result1)) != 0) __builtin_abort (); }while (0);;
  do { __typeof__((numbers << allones)) result1 = (numbers << allones); if(sizeof (result1) != sizeof (numbersleftshiftallones)) __builtin_abort (); if (__builtin_memcmp (&result1, &numbersleftshiftallones, sizeof(result1)) != 0) __builtin_abort (); }while (0);;
  do { __typeof__((numbers >> allones)) result1 = (numbers >> allones); if(sizeof (result1) != sizeof (numbersrightshiftallones)) __builtin_abort (); if (__builtin_memcmp (&result1, &numbersrightshiftallones, sizeof(result1)) != 0) __builtin_abort (); }while (0);;


  do { __typeof__((numbers << allones) >> allones) result1 = (numbers << allones) >> allones; if(sizeof (result1) != sizeof (numbers)) __builtin_abort (); if (__builtin_memcmp (&result1, &numbers, sizeof(result1)) != 0) __builtin_abort (); }while (0);;



  do { __typeof__((unumbers << uallzeros)) result1 = (unumbers << uallzeros); if(sizeof (result1) != sizeof (unumbers)) __builtin_abort (); if (__builtin_memcmp (&result1, &unumbers, sizeof(result1)) != 0) __builtin_abort (); }while (0);;
  do { __typeof__((unumbers >> uallzeros)) result1 = (unumbers >> uallzeros); if(sizeof (result1) != sizeof (unumbers)) __builtin_abort (); if (__builtin_memcmp (&result1, &unumbers, sizeof(result1)) != 0) __builtin_abort (); }while (0);;
  do { __typeof__((unumbers << uallones)) result1 = (unumbers << uallones); if(sizeof (result1) != sizeof (unumbersleftshiftallones)) __builtin_abort (); if (__builtin_memcmp (&result1, &unumbersleftshiftallones, sizeof(result1)) != 0) __builtin_abort (); }while (0);;
  do { __typeof__((unumbers >> uallones)) result1 = (unumbers >> uallones); if(sizeof (result1) != sizeof (unumbersrightshiftallones)) __builtin_abort (); if (__builtin_memcmp (&result1, &unumbersrightshiftallones, sizeof(result1)) != 0) __builtin_abort (); }while (0);;


  do { __typeof__((unumbers << uallones) >> uallones) result1 = (unumbers << uallones) >> uallones; if(sizeof (result1) != sizeof (unumbers)) __builtin_abort (); if (__builtin_memcmp (&result1, &unumbers, sizeof(result1)) != 0) __builtin_abort (); }while (0);;

  return 0;
}
