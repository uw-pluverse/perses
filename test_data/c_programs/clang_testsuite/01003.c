int __attribute__((target("x87"))) foo(int a) { return 4; }
int __attribute__((target("no-x87"))) bar(int a) { return 4; }
