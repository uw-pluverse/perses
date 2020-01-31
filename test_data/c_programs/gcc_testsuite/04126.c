


int a[sizeof(int) == 4 ? 1 : -1];
int b[sizeof(long) == 8 ? 1 : -1];
int c[sizeof(long long) == 8 ? 1 : -1];
int d[sizeof(short) == 2 ? 1 : -1];
int e[sizeof(void *) == 8 ? 1 : -1];
int f[sizeof(float) == 4 ? 1 : -1];
int g[sizeof(double) == 8 ? 1 : -1];
int h[sizeof(long double) == 16 ? 1 : -1];
int i[sizeof(long unsigned int) == 8 ? 1 : -1];
int j[sizeof(int) == 4 ? 1 : -1];
int k[sizeof(unsigned int) == 4 ? 1 : -1];
int l[sizeof(long int) == 8 ? 1 : -1];
