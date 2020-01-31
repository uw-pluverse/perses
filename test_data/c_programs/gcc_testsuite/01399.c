






struct A {
 char a[400];
 float* c;
};
struct A glob;
void func();
void func1(float*);
int func2(float*, int*);
void func3(float*);

void test(int *p) {
 func1(glob.c);
 if (func2(glob.c, p)) {
   func();
 }
 func3(glob.c);
}
