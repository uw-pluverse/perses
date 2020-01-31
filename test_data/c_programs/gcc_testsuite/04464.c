






int main (int argc, char *argv[]) {
    __attribute__((vector_size((4)*sizeof(unsigned int)))) unsigned int vuint = { 1, 2, 3, 4};
    __attribute__((vector_size((4)*sizeof(int)))) int vint0 = { 1, 1, 1, 1};
    __attribute__((vector_size((4)*sizeof(int)))) int vint1 = {-1, -1, -1, -1};

    __attribute__((vector_size((4)*sizeof(int)))) int i1, i2, i3;
    __attribute__((vector_size((4)*sizeof(unsigned int)))) unsigned int u1, u2, u3;

    i1 = vint1<< vint0;

    if ((*((int *) &(i1) + 0)) != ((int)-1 << (int)1))
        __builtin_abort ();
    if ((*((int *) &(i1) + 1)) != ((int)-1 << (int)1))
        __builtin_abort ();
    if ((*((int *) &(i1) + 2)) != ((int)-1 << (int)1))
        __builtin_abort ();
    if ((*((int *) &(i1) + 3)) != ((int)-1 << (int)1))
        __builtin_abort ();

    u1 = vuint << vint0;

    if ((*((int *) &(u1) + 0)) != ((unsigned int)1 << (int)1))
        __builtin_abort ();
    if ((*((int *) &(u1) + 1)) != ((unsigned int)2 << (int)1))
        __builtin_abort ();
    if ((*((int *) &(u1) + 2)) != ((unsigned int)3 << (int)1))
        __builtin_abort ();
    if ((*((int *) &(u1) + 3)) != ((unsigned int)4 << (int)1))
        __builtin_abort ();


    i2 = vint1 >> vuint;

    if ((*((int *) &(i2) + 0)) != ((int)-1 >> (unsigned int)1))
        __builtin_abort ();
    if ((*((int *) &(i2) + 1)) != ((int)-1 >> (unsigned int)2))
        __builtin_abort ();
    if ((*((int *) &(i2) + 2)) != ((int)-1 >> (unsigned int)3))
        __builtin_abort ();
    if ((*((int *) &(i2) + 3)) != ((int)-1 >> (unsigned int)4))
        __builtin_abort ();


    vint1 >>= vuint;

    vuint <<= vint0;
    vuint <<= vint1;


    return 0;
}
