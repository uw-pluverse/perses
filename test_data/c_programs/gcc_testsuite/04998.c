typedef int v2si __attribute__ ((vector_size (4 * 2))); int foo2(int x, v2si v) { v[0] ^= v[1]; return ((v2si)v)[x]; } int bar2(int x, v2si v) { v[0] ^= v[1]; return v[x]; }
typedef int v4si __attribute__ ((vector_size (4 * 4))); int foo4(int x, v4si v) { v[0] ^= v[1]; return ((v4si)v)[x]; } int bar4(int x, v4si v) { v[0] ^= v[1]; return v[x]; }
typedef int v8si __attribute__ ((vector_size (4 * 8))); int foo8(int x, v8si v) { v[0] ^= v[1]; return ((v8si)v)[x]; } int bar8(int x, v8si v) { v[0] ^= v[1]; return v[x]; }
typedef int v16si __attribute__ ((vector_size (4 * 16))); int foo16(int x, v16si v) { v[0] ^= v[1]; return ((v16si)v)[x]; } int bar16(int x, v16si v) { v[0] ^= v[1]; return v[x]; }
typedef int v32si __attribute__ ((vector_size (4 * 32))); int foo32(int x, v32si v) { v[0] ^= v[1]; return ((v32si)v)[x]; } int bar32(int x, v32si v) { v[0] ^= v[1]; return v[x]; }
typedef int v64si __attribute__ ((vector_size (4 * 64))); int foo64(int x, v64si v) { v[0] ^= v[1]; return ((v64si)v)[x]; } int bar64(int x, v64si v) { v[0] ^= v[1]; return v[x]; }
