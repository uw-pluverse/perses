


struct S {
    long l;
    unsigned char c;
};
unsigned long f(unsigned char *p10) {
    struct S *p = (struct S *) (p10 + 10);
    return p->c;
}
