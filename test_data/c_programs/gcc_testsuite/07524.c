


void f(unsigned char *s, unsigned char *d, int n) {
    int i;
    for (i = 0; i < n; i += 4) {
        d[i + 0] += s[i + 0];
        d[i + 1] += s[i + 1];
        d[i + 2] += s[i + 2];
        d[i + 3] += s[i + 3];
    }
}
