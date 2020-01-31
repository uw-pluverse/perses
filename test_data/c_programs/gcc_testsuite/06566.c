int main (int argc, char *argv[]) {
    __attribute__((vector_size((16)*sizeof(unsigned char)))) unsigned char vuchar = { 1,2,3,4, 1,2,3,4, 1,2,3,4, 1,2,3,4};
    __attribute__((vector_size((16)*sizeof(signed char)))) signed char vchar0 = { 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
    __attribute__((vector_size((16)*sizeof(signed char)))) signed char vchar1 = { -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1};

    __attribute__((vector_size((16)*sizeof(signed char)))) signed char i1, i2, i3;
    __attribute__((vector_size((16)*sizeof(unsigned char)))) unsigned char u1, u2, u3;

    i1 = vchar1<< vchar0;

    if ((*((signed char *) &(i1) + 0)) != ((signed char)-1 << (signed char)1))
        __builtin_abort ();
    if ((*((signed char *) &(i1) + 1)) != ((signed char)-1 << (signed char)1))
        __builtin_abort ();
    if ((*((signed char *) &(i1) + 2)) != ((signed char)-1 << (signed char)1))
        __builtin_abort ();
    if ((*((signed char *) &(i1) + 3)) != ((signed char)-1 << (signed char)1))
        __builtin_abort ();
    u1 = vuchar << vchar0;

    if ((*((unsigned char *) &(u1) + 0)) != ((unsigned char)1 << (signed char)1))
        __builtin_abort ();
    if ((*((unsigned char *) &(u1) + 1)) != ((unsigned char)2 << (signed char)1))
        __builtin_abort ();
    if ((*((unsigned char *) &(u1) + 2)) != ((unsigned char)3 << (signed char)1))
        __builtin_abort ();
    if ((*((unsigned char *) &(u1) + 3)) != ((unsigned char)4 << (signed char)1))
        __builtin_abort ();


    i2 = vchar1 >> vuchar;

    if ((*((signed char *) &(i2) + 0)) != ((signed char)-1 >> (unsigned char)1))
        __builtin_abort ();
    if ((*((signed char *) &(i2) + 1)) != ((signed char)-1 >> (unsigned char)2))
        __builtin_abort ();
    if ((*((signed char *) &(i2) + 2)) != ((signed char)-1 >> (unsigned char)3))
        __builtin_abort ();
    if ((*((signed char *) &(i2) + 3)) != ((signed char)-1 >> (unsigned char)4))
        __builtin_abort ();

    vchar1 >>= vuchar;
    vuchar <<= vchar0;
    vuchar <<= vchar1;

    return 0;
}
