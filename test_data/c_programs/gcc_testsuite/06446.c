





typedef unsigned short char16_t;
typedef unsigned int char32_t;

extern void f_c (char);
extern void fsc (signed char);
extern void fuc (unsigned char);
extern void f_s (short);
extern void fss (signed short);
extern void fus (unsigned short);
extern void f_i (int);
extern void fsi (signed int);
extern void fui (unsigned int);
extern void f_l (long);
extern void fsl (signed long);
extern void ful (unsigned long);
extern void f_ll (long long);
extern void fsll (signed long long);
extern void full (unsigned long long);

void m (char16_t c0, char32_t c1)
{
    f_c (c0);
    fsc (c0);
    fuc (c0);
    f_s (c0);
    fss (c0);
    fus (c0);
    f_i (c0);
    fsi (c0);
    fui (c0);
    f_l (c0);
    fsl (c0);
    ful (c0);
    f_ll (c0);
    fsll (c0);
    full (c0);

    f_c (c1);
    fsc (c1);
    fuc (c1);
    f_s (c1);
    fss (c1);
    fus (c1);
    f_i (c1);
    fsi (c1);
    fui (c1);
    f_l (c1);
    fsl (c1);
    ful (c1);
    f_ll (c1);
    fsll (c1);
    full (c1);
}
