


double a[10];
int f(int n){
  a[3]=9;
  __builtin_memset(&a[n],3,sizeof(double));
  return a[3]==9;
}
