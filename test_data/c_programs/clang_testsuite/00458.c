char pass_char(char arg) { return arg; }
short pass_short(short arg) { return arg; }
int pass_int(int arg) { return arg; }
long pass_long(long arg) { return arg; }
long long pass_longlong(long long arg) { return arg; }
__int128 pass_int128(__int128 arg) { return arg; }
float pass_float(float arg) { return arg; }
double pass_double(double arg) { return arg; }
long double pass_longdouble(long double arg) { return arg; }
_Complex char pass_complex_char(_Complex char arg) { return arg; }
_Complex short pass_complex_short(_Complex short arg) { return arg; }
_Complex int pass_complex_int(_Complex int arg) { return arg; }
_Complex long pass_complex_long(_Complex long arg) { return arg; }
_Complex long long pass_complex_longlong(_Complex long long arg) { return arg; }
_Complex float pass_complex_float(_Complex float arg) { return arg; }
_Complex double pass_complex_double(_Complex double arg) { return arg; }
_Complex long double pass_complex_longdouble(_Complex long double arg) { return arg; }
struct agg_1byte { char a[1]; };
struct agg_1byte pass_agg_1byte(struct agg_1byte arg) { return arg; }
struct agg_2byte { char a[2]; };
struct agg_2byte pass_agg_2byte(struct agg_2byte arg) { return arg; }
struct agg_3byte { char a[3]; };
struct agg_3byte pass_agg_3byte(struct agg_3byte arg) { return arg; }
struct agg_4byte { char a[4]; };
struct agg_4byte pass_agg_4byte(struct agg_4byte arg) { return arg; }
struct agg_5byte { char a[5]; };
struct agg_5byte pass_agg_5byte(struct agg_5byte arg) { return arg; }
struct agg_6byte { char a[6]; };
struct agg_6byte pass_agg_6byte(struct agg_6byte arg) { return arg; }
struct agg_7byte { char a[7]; };
struct agg_7byte pass_agg_7byte(struct agg_7byte arg) { return arg; }
struct agg_8byte { char a[8]; };
struct agg_8byte pass_agg_8byte(struct agg_8byte arg) { return arg; }
struct agg_16byte { char a[16]; };
struct agg_16byte pass_agg_16byte(struct agg_16byte arg) { return arg; }
struct agg_float { float a; };
struct agg_float pass_agg_float(struct agg_float arg) { return arg; }
struct agg_double { double a; };
struct agg_double pass_agg_double(struct agg_double arg) { return arg; }
struct agg_longdouble { long double a; };
struct agg_longdouble pass_agg_longdouble(struct agg_longdouble arg) { return arg; }
struct agg_float_a8 { float a __attribute__((aligned (8))); };
struct agg_float_a8 pass_agg_float_a8(struct agg_float_a8 arg) { return arg; }
struct agg_float_a16 { float a __attribute__((aligned (16))); };
struct agg_float_a16 pass_agg_float_a16(struct agg_float_a16 arg) { return arg; }
struct agg_nofloat1 { float a; float b; };
struct agg_nofloat1 pass_agg_nofloat1(struct agg_nofloat1 arg) { return arg; }
struct agg_nofloat2 { float a; int b; };
struct agg_nofloat2 pass_agg_nofloat2(struct agg_nofloat2 arg) { return arg; }
struct agg_nofloat3 { float a; int : 0; };
struct agg_nofloat3 pass_agg_nofloat3(struct agg_nofloat3 arg) { return arg; }
int va_int(__builtin_va_list l) { return __builtin_va_arg(l, int); }
long va_long(__builtin_va_list l) { return __builtin_va_arg(l, long); }
long long va_longlong(__builtin_va_list l) { return __builtin_va_arg(l, long long); }
double va_double(__builtin_va_list l) { return __builtin_va_arg(l, double); }
long double va_longdouble(__builtin_va_list l) { return __builtin_va_arg(l, long double); }
_Complex char va_complex_char(__builtin_va_list l) { return __builtin_va_arg(l, _Complex char); }
struct agg_1byte va_agg_1byte(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_1byte); }
struct agg_2byte va_agg_2byte(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_2byte); }
struct agg_3byte va_agg_3byte(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_3byte); }
struct agg_4byte va_agg_4byte(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_4byte); }
struct agg_8byte va_agg_8byte(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_8byte); }
struct agg_float va_agg_float(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_float); }
struct agg_double va_agg_double(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_double); }
struct agg_longdouble va_agg_longdouble(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_longdouble); }
struct agg_float_a8 va_agg_float_a8(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_float_a8); }
struct agg_float_a16 va_agg_float_a16(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_float_a16); }
struct agg_nofloat1 va_agg_nofloat1(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_nofloat1); }
struct agg_nofloat2 va_agg_nofloat2(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_nofloat2); }
struct agg_nofloat3 va_agg_nofloat3(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_nofloat3); }
