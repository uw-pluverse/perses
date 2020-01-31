int __attribute__((target("avx,sse4.2,arch=ivybridge"))) foo() { return 4; }
int __attribute__((target())) bar() { return 4; }
int __attribute__((target("tune=sandybridge"))) baz() { return 4; }
int __attribute__((target("fpmath=387"))) walrus() { return 4; }
