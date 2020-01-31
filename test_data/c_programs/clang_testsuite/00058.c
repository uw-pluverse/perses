typedef unsigned int __uint32_t;
typedef __uint32_t __darwin_socklen_t;
typedef __darwin_socklen_t socklen_t;
int getsockopt(int, int, int, void * restrict, socklen_t * restrict);
int test1() {
  int s = -1;
  int size;
  socklen_t size_len = sizeof(size);
  if (getsockopt(s, 0xffff, 0x1001, (char *)&size, &size_len) < 0)
          return -1;
  return size;
}
int takes_charptr(char* p);
int test2() {
  int size;
  if (takes_charptr((char*)&size))
    return -1;
  return size;
}
