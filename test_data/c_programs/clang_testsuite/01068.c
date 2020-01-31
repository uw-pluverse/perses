extern int a[] __attribute__((weak));
int b[] = {8,13,21};
struct {
  int x[10];
} c;
const char str[] = "text";
void ignore() {
  if (!a) {}
}
void test() {
  if (!b) {}
  if (b == 0) {}
  if (!c.x) {}
  if (c.x == 0) {}
  if (!str) {}
  if (0 == str) {}
}
int array[2];
int test1()
{
  if (!array) {
    return array[0];
  } else if (array != 0) {
    return array[1];
  }
  if (array == 0)
    return 1;
  return 0;
}
int test2(int* pointer, char ch, void * pv) {
   if (!&pointer) {
     return 0;
   }
   if (&pointer) {
     return 0;
   }
   if (&pointer == (void*)0) {}
   if (&pointer != (void*)0) {}
   return 1;
}
void test3() {
   if (array) { }
   if (array != 0) {}
   if (!array) { }
   if (array == 0) {}
   if (array[0] &&
       array) {}
   if (array[0] ||
       array) {}
   if (array[0] &&
       !array) {}
   if (array[0] ||
       !array) {}
   if (array &&
       array[0]) {}
   if (!array ||
       array[0]) {}
   if (array ||
       (!array && array[0])) {}
 }
void _HTTPClientErrorHandler(int me)
{
  int *result;
  if( (&me) && (&result) ) *result=*&me;;
}
void test_conditional_operator() {
  int x;
  x = b ? 1 : 0;
  x = c.x ? 1 : 0;
  x = str ? 1 : 0;
  x = array ? 1 : 0;
  x = &x ? 1 : 0;
}
