vector int test0 = (vector int)(1);
vector float test1 = (vector float)(1.0);
vector char v1 = (vector char)((vector int)(1, 2, 3, 4));
vector char v2 = (vector char)((vector float)(1.0f, 2.0f, 3.0f, 4.0f));
vector char v3 = (vector char)((vector int)('a', 'b', 'c', 'd'));
vector int v4 = (vector char){1, 2, 3, 4};
void test2()
{
  vector int vi;
  vector float vf;
  vi = (vector int)(1);
  vf = (vector float)(1.0);
  vi = (vector int)(1, 2, 3, 4);
  vi = (vector int)(1, 2, 3, 4, 5);
  vi = (vector int){1};
  vi = (vector int){1, 2};
  vi = (vector int){1, 2, 3, 4};
}
void test3() {
  vector int vi;
  vi++;
  vector unsigned int vui;
  --vui;
  vector float vf;
  vf++;
}
