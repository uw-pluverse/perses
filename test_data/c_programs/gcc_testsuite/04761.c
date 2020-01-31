



__attribute__((vector_size(4*sizeof(int)) )) int a, b, c;



void f(void)
{
  a = b % c;
}
