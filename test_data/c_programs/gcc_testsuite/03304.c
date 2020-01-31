





char x __attribute__((aligned(128),vector_size(2)));


int f[__alignof__(x) == 128?1:-1];
