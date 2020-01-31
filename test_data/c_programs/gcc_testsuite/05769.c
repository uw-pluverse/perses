


int f(int n){
  int*p;
  {
    int yyy=n;
    p=&yyy;
  }
  return *p;
}
