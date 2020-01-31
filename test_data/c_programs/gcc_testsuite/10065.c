







static const int ZERO = 0;
static const double DZERO = 0;

int *a;
int b;
long *c;
void
foo (void)
{
  (b = *(1 ? a : (0)));
  (c = (1 ? a : (void *)(long unsigned int)(ZERO)));
  (b = *(1 ? a : (0 + 0)));
  (c = (1 ? a : (void *)(long unsigned int)(ZERO + 0)));
  (c = (1 ? a : (void *)(long unsigned int)(ZERO + ZERO)));
  (b = *(1 ? a : (+0)));
  (c = (1 ? a : (void *)(long unsigned int)(+ZERO)));
  (b = *(1 ? a : (-0)));
  (c = (1 ? a : (void *)(long unsigned int)(-ZERO)));
  (b = *(1 ? a : ((char) 0)));
  (c = (1 ? a : (void *)(long unsigned int)((char) ZERO)));
  (b = *(1 ? a : ((int) 0)));
  (c = (1 ? a : (void *)(long unsigned int)((int) ZERO)));
  (b = *(1 ? a : ((int) 0.0)));
  (c = (1 ? a : (void *)(long unsigned int)((int) DZERO)));
  (c = (1 ? a : (void *)(long unsigned int)((int) +0.0)));
  (c = (1 ? a : (void *)(long unsigned int)((int) (0.0+0.0))));
  (c = (1 ? a : (void *)(long unsigned int)((int) (double)0.0)));
}
