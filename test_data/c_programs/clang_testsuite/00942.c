static int foo(int a)
{
 static int b = 1;
 return b+a;
}
int main() {
 int j = foo(1);
 return 0;
}
