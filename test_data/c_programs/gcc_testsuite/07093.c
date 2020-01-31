



struct s { int x[4]; };
struct s my_struct __attribute__((__section__(".sdata")));

int f() { return my_struct.x[0]; }
