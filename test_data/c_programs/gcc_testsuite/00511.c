






extern void abort (void);
extern int memcmp (const void *, const void *, long unsigned int);

typedef __attribute__ ((vector_size (16))) unsigned char v16qi;
typedef __attribute__ ((vector_size (16))) unsigned short v8hi;
typedef __attribute__ ((vector_size (16))) unsigned int v4si;

typedef __attribute__((aligned(16))) char c16[16];
typedef __attribute__((aligned(16))) short s8[8];
typedef __attribute__((aligned(16))) int i4[4];
void __attribute__ ((noinline)) check_v16qi (v16qi v1, char *v2)
{
  if (memcmp (&v1, v2, 16))
    abort ();
}

void __attribute__ ((noinline)) check_v8hi (v8hi v1, short *v2)
{
  if (memcmp (&v1, v2, 16))
    abort ();
}

void __attribute__ ((noinline)) check_v4si (v4si v1, int *v2)
{
  if (memcmp (&v1, v2, 16))
    abort ();
}




void v16qi_vspltisb ()
{
  v16qi v = {15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15}; static c16 w = {15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15}; check_v16qi (v, w);;
}

void v16qi_vspltisb_neg ()
{
  v16qi v = {-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5}; static c16 w = {-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,-5}; check_v16qi (v, w);;
}

void v16qi_vspltisb_addself ()
{
  v16qi v = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30}; static c16 w = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30}; check_v16qi (v, w);;
}

void v16qi_vspltisb_neg_addself ()
{
  v16qi v = {-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24}; static c16 w = {-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24}; check_v16qi (v, w);;
}

void v16qi_vspltish ()
{
  v16qi v = {0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,15}; static c16 w = {0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,15}; check_v16qi (v, w);;
}

void v16qi_vspltish_addself ()
{
  v16qi v = {0,30,0,30,0,30,0,30,0,30,0,30,0,30,0,30}; static c16 w = {0,30,0,30,0,30,0,30,0,30,0,30,0,30,0,30}; check_v16qi (v, w);;
}

void v16qi_vspltish_neg ()
{
  v16qi v = {-1,-5,-1,-5,-1,-5,-1,-5,-1,-5,-1,-5,-1,-5,-1,-5}; static c16 w = {-1,-5,-1,-5,-1,-5,-1,-5,-1,-5,-1,-5,-1,-5,-1,-5}; check_v16qi (v, w);;
}

void v16qi_vspltisw ()
{
  v16qi v = {0,0,0,15,0,0,0,15,0,0,0,15,0,0,0,15}; static c16 w = {0,0,0,15,0,0,0,15,0,0,0,15,0,0,0,15}; check_v16qi (v, w);;
}

void v16qi_vspltisw_addself ()
{
  v16qi v = {0,0,0,30,0,0,0,30,0,0,0,30,0,0,0,30}; static c16 w = {0,0,0,30,0,0,0,30,0,0,0,30,0,0,0,30}; check_v16qi (v, w);;
}

void v16qi_vspltisw_neg ()
{
  v16qi v = {-1,-1,-1,-5,-1,-1,-1,-5,-1,-1,-1,-5,-1,-1,-1,-5}; static c16 w = {-1,-1,-1,-5,-1,-1,-1,-5,-1,-1,-1,-5,-1,-1,-1,-5}; check_v16qi (v, w);;
}




void v8hi_vspltisb ()
{
  v8hi v = {0x0F0F,0x0F0F,0x0F0F,0x0F0F,0x0F0F,0x0F0F,0x0F0F,0x0F0F}; static s8 w = {0x0F0F,0x0F0F,0x0F0F,0x0F0F,0x0F0F,0x0F0F,0x0F0F,0x0F0F}; check_v8hi (v, w);;
}

void v8hi_vspltisb_addself ()
{
  v8hi v = {0x1E1E,0x1E1E,0x1E1E,0x1E1E,0x1E1E,0x1E1E,0x1E1E,0x1E1E}; static s8 w = {0x1E1E,0x1E1E,0x1E1E,0x1E1E,0x1E1E,0x1E1E,0x1E1E,0x1E1E}; check_v8hi (v, w);;
}

void v8hi_vspltisb_neg ()
{
  v8hi v = {0xFBFB,0xFBFB,0xFBFB,0xFBFB,0xFBFB,0xFBFB,0xFBFB,0xFBFB}; static s8 w = {0xFBFB,0xFBFB,0xFBFB,0xFBFB,0xFBFB,0xFBFB,0xFBFB,0xFBFB}; check_v8hi (v, w);;
}

void v8hi_vspltish ()
{
  v8hi v = {15,15,15,15,15,15,15,15}; static s8 w = {15,15,15,15,15,15,15,15}; check_v8hi (v, w);;
}

void v8hi_vspltish_neg ()
{
  v8hi v = {-5,-5,-5,-5,-5,-5,-5,-5}; static s8 w = {-5,-5,-5,-5,-5,-5,-5,-5}; check_v8hi (v, w);;
}

void v8hi_vspltish_addself ()
{
  v8hi v = {30,30,30,30,30,30,30,30}; static s8 w = {30,30,30,30,30,30,30,30}; check_v8hi (v, w);;
}

void v8hi_vspltish_neg_addself ()
{
  v8hi v = {-24,-24,-24,-24,-24,-24,-24,-24}; static s8 w = {-24,-24,-24,-24,-24,-24,-24,-24}; check_v8hi (v, w);;
}

void v8hi_vspltisw ()
{
  v8hi v = {0,15,0,15,0,15,0,15}; static s8 w = {0,15,0,15,0,15,0,15}; check_v8hi (v, w);;
}

void v8hi_vspltisw_addself ()
{
  v8hi v = {0,30,0,30,0,30,0,30}; static s8 w = {0,30,0,30,0,30,0,30}; check_v8hi (v, w);;
}

void v8hi_vspltisw_neg ()
{
  v8hi v = {-1,-5,-1,-5,-1,-5,-1,-5}; static s8 w = {-1,-5,-1,-5,-1,-5,-1,-5}; check_v8hi (v, w);;
}



void v4si_vspltisb ()
{
  v4si v = {0x0F0F0F0F,0x0F0F0F0F,0x0F0F0F0F,0x0F0F0F0F}; static i4 w = {0x0F0F0F0F,0x0F0F0F0F,0x0F0F0F0F,0x0F0F0F0F}; check_v4si (v, w);;
}

void v4si_vspltisb_addself ()
{
  v4si v = {0x1E1E1E1E,0x1E1E1E1E,0x1E1E1E1E,0x1E1E1E1E}; static i4 w = {0x1E1E1E1E,0x1E1E1E1E,0x1E1E1E1E,0x1E1E1E1E}; check_v4si (v, w);;
}

void v4si_vspltisb_neg ()
{
  v4si v = {0xFBFBFBFB,0xFBFBFBFB,0xFBFBFBFB,0xFBFBFBFB}; static i4 w = {0xFBFBFBFB,0xFBFBFBFB,0xFBFBFBFB,0xFBFBFBFB}; check_v4si (v, w);;
}

void v4si_vspltish ()
{
  v4si v = {0x000F000F,0x000F000F,0x000F000F,0x000F000F}; static i4 w = {0x000F000F,0x000F000F,0x000F000F,0x000F000F}; check_v4si (v, w);;
}

void v4si_vspltish_addself ()
{
  v4si v = {0x001E001E,0x001E001E,0x001E001E,0x001E001E}; static i4 w = {0x001E001E,0x001E001E,0x001E001E,0x001E001E}; check_v4si (v, w);;
}

void v4si_vspltish_neg ()
{
  v4si v = {0xFFFBFFFB,0xFFFBFFFB,0xFFFBFFFB,0xFFFBFFFB}; static i4 w = {0xFFFBFFFB,0xFFFBFFFB,0xFFFBFFFB,0xFFFBFFFB}; check_v4si (v, w);;
}

void v4si_vspltisw ()
{
  v4si v = {15,15,15,15}; static i4 w = {15,15,15,15}; check_v4si (v, w);;
}

void v4si_vspltisw_neg ()
{
  v4si v = {-5,-5,-5,-5}; static i4 w = {-5,-5,-5,-5}; check_v4si (v, w);;
}

void v4si_vspltisw_addself ()
{
  v4si v = {30,30,30,30}; static i4 w = {30,30,30,30}; check_v4si (v, w);;
}

void v4si_vspltisw_neg_addself ()
{
  v4si v = {-24,-24,-24,-24}; static i4 w = {-24,-24,-24,-24}; check_v4si (v, w);;
}



int main ()
{
  v16qi_vspltisb ();
  v16qi_vspltisb_neg ();
  v16qi_vspltisb_addself ();
  v16qi_vspltisb_neg_addself ();
  v16qi_vspltish ();
  v16qi_vspltish_addself ();
  v16qi_vspltish_neg ();
  v16qi_vspltisw ();
  v16qi_vspltisw_addself ();
  v16qi_vspltisw_neg ();

  v8hi_vspltisb ();
  v8hi_vspltisb_addself ();
  v8hi_vspltisb_neg ();
  v8hi_vspltish ();
  v8hi_vspltish_neg ();
  v8hi_vspltish_addself ();
  v8hi_vspltish_neg_addself ();
  v8hi_vspltisw ();
  v8hi_vspltisw_addself ();
  v8hi_vspltisw_neg ();

  v4si_vspltisb ();
  v4si_vspltisb_addself ();
  v4si_vspltisb_neg ();
  v4si_vspltish ();
  v4si_vspltish_addself ();
  v4si_vspltish_neg ();
  v4si_vspltisw ();
  v4si_vspltisw_neg ();
  v4si_vspltisw_addself ();
  v4si_vspltisw_neg_addself ();
  return 0;
}
