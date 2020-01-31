typedef long int64_t;
int64_t f_load_madd_64(int64_t a, int64_t b, int64_t *c) {
    int64_t result = a+b*(*c);
    return result;
}
