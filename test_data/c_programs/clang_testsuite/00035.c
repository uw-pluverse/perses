unsigned getArraySize(int *x) {
  if (!x)
    return *x;
  return 1;
}
int testVariablyModifiedTypes(int *x) {
  int mytype[getArraySize(x)];
  return 0;
}
