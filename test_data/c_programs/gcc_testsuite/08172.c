struct S {
  int key;
  int rnext,rprev;
};

void foo(struct S* H)
{
  int i, k;
  for (i=0; i<2; i++){
    struct S* cell=H+k;
    cell->key=i*(0xffffffffUL/2);
    cell->rnext=k+(1-i);
    cell->rprev=k+(1-i);
  }
}
