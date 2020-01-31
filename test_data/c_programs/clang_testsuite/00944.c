int baz(int a) { return 4; }
int __attribute__((target("avx,sse4.2,arch=ivybridge"))) foo(int a) { return 4; }
int __attribute__((target("tune=sandybridge"))) walrus(int a) { return 4; }
int __attribute__((target("fpmath=387"))) koala(int a) { return 4; }
int __attribute__((target("no-sse2"))) echidna(int a) { return 4; }
int __attribute__((target("sse4"))) panda(int a) { return 4; }
int bar(int a) { return baz(a) + foo(a); }
int __attribute__((target("avx,      sse4.2,      arch=   ivybridge"))) qux(int a) { return 4; }
int __attribute__((target("no-aes, arch=ivybridge"))) qax(int a) { return 4; }
int __attribute__((target("no-mmx"))) qq(int a) { return 40; }
int __attribute__((target("arch=lakemont"))) lake(int a) { return 4; }
