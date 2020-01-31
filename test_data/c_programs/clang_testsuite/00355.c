static int highly_aligned __attribute__((aligned(4096)));
int f() {
 return highly_aligned;
}
