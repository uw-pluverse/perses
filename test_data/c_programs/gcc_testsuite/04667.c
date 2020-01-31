



typedef struct A { int a,b; } A;
int*g(int*x){return x;}
int*f1(){
  A x[2]={{1,2},{3,4}};
  return g(&x[1].a);
}
int*f2(int n){
  A x[2]={{1,2},{3,4}};
  return n?0:g(&x[1].a);
}
A y[2]={{1,2},{3,4}};
int*h(){
  return g(&y[1].a);
}
int*j(int n){
  A x[2]={{1,2},{3,4}};
  int*p=g(&y[1].a);
  if(n==1)p=g(&x[1].a);
  if(n==2)p=g(&x[0].b);
  return p;
}
int*s()
{
  static int i;
  return &i;
}
