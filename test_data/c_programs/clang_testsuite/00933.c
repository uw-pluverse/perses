typedef union {
  int i;
  float f;
} MyUnion;
void unionf(MyUnion a);
void uniontest(float a) {
  f((MyUnion)1.0f);
}
