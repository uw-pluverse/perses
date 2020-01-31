typedef __attribute__((vector_size(1))) char v1i8;
typedef __attribute__((vector_size(2))) char v2i8;
typedef __attribute__((vector_size(2))) short v1i16;
typedef __attribute__((vector_size(4))) char v4i8;
typedef __attribute__((vector_size(4))) short v2i16;
typedef __attribute__((vector_size(4))) int v1i32;
typedef __attribute__((vector_size(4))) float v1f32;
typedef __attribute__((vector_size(8))) char v8i8;
typedef __attribute__((vector_size(8))) short v4i16;
typedef __attribute__((vector_size(8))) int v2i32;
typedef __attribute__((vector_size(8))) long long v1i64;
typedef __attribute__((vector_size(8))) float v2f32;
typedef __attribute__((vector_size(8))) double v1f64;
typedef __attribute__((vector_size(16))) char v16i8;
typedef __attribute__((vector_size(16))) short v8i16;
typedef __attribute__((vector_size(16))) int v4i32;
typedef __attribute__((vector_size(16))) long long v2i64;
typedef __attribute__((vector_size(16))) __int128 v1i128;
typedef __attribute__((vector_size(16))) float v4f32;
typedef __attribute__((vector_size(16))) double v2f64;
typedef __attribute__((vector_size(16))) long double v1f128;
typedef __attribute__((vector_size(32))) char v32i8;
unsigned int align = __alignof__ (v16i8);
v1i8 pass_v1i8(v1i8 arg) { return arg; }
v2i8 pass_v2i8(v2i8 arg) { return arg; }
v4i8 pass_v4i8(v4i8 arg) { return arg; }
v8i8 pass_v8i8(v8i8 arg) { return arg; }
v16i8 pass_v16i8(v16i8 arg) { return arg; }
v32i8 pass_v32i8(v32i8 arg) { return arg; }
v1i16 pass_v1i16(v1i16 arg) { return arg; }
v2i16 pass_v2i16(v2i16 arg) { return arg; }
v4i16 pass_v4i16(v4i16 arg) { return arg; }
v8i16 pass_v8i16(v8i16 arg) { return arg; }
v1i32 pass_v1i32(v1i32 arg) { return arg; }
v2i32 pass_v2i32(v2i32 arg) { return arg; }
v4i32 pass_v4i32(v4i32 arg) { return arg; }
v1i64 pass_v1i64(v1i64 arg) { return arg; }
v2i64 pass_v2i64(v2i64 arg) { return arg; }
v1i128 pass_v1i128(v1i128 arg) { return arg; }
v1f32 pass_v1f32(v1f32 arg) { return arg; }
v2f32 pass_v2f32(v2f32 arg) { return arg; }
v4f32 pass_v4f32(v4f32 arg) { return arg; }
v1f64 pass_v1f64(v1f64 arg) { return arg; }
v2f64 pass_v2f64(v2f64 arg) { return arg; }
v1f128 pass_v1f128(v1f128 arg) { return arg; }
struct agg_v1i8 { v1i8 a; };
struct agg_v1i8 pass_agg_v1i8(struct agg_v1i8 arg) { return arg; }
struct agg_v2i8 { v2i8 a; };
struct agg_v2i8 pass_agg_v2i8(struct agg_v2i8 arg) { return arg; }
struct agg_v4i8 { v4i8 a; };
struct agg_v4i8 pass_agg_v4i8(struct agg_v4i8 arg) { return arg; }
struct agg_v8i8 { v8i8 a; };
struct agg_v8i8 pass_agg_v8i8(struct agg_v8i8 arg) { return arg; }
struct agg_v16i8 { v16i8 a; };
struct agg_v16i8 pass_agg_v16i8(struct agg_v16i8 arg) { return arg; }
struct agg_v32i8 { v32i8 a; };
struct agg_v32i8 pass_agg_v32i8(struct agg_v32i8 arg) { return arg; }
struct agg_novector1 { v4i8 a; v4i8 b; };
struct agg_novector1 pass_agg_novector1(struct agg_novector1 arg) { return arg; }
struct agg_novector2 { v4i8 a; float b; };
struct agg_novector2 pass_agg_novector2(struct agg_novector2 arg) { return arg; }
struct agg_novector3 { v4i8 a; int : 0; };
struct agg_novector3 pass_agg_novector3(struct agg_novector3 arg) { return arg; }
struct agg_novector4 { v4i8 a __attribute__((aligned (8))); };
struct agg_novector4 pass_agg_novector4(struct agg_novector4 arg) { return arg; }
v1i8 va_v1i8(__builtin_va_list l) { return __builtin_va_arg(l, v1i8); }
v2i8 va_v2i8(__builtin_va_list l) { return __builtin_va_arg(l, v2i8); }
v4i8 va_v4i8(__builtin_va_list l) { return __builtin_va_arg(l, v4i8); }
v8i8 va_v8i8(__builtin_va_list l) { return __builtin_va_arg(l, v8i8); }
v16i8 va_v16i8(__builtin_va_list l) { return __builtin_va_arg(l, v16i8); }
v32i8 va_v32i8(__builtin_va_list l) { return __builtin_va_arg(l, v32i8); }
struct agg_v1i8 va_agg_v1i8(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_v1i8); }
struct agg_v2i8 va_agg_v2i8(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_v2i8); }
struct agg_v4i8 va_agg_v4i8(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_v4i8); }
struct agg_v8i8 va_agg_v8i8(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_v8i8); }
struct agg_v16i8 va_agg_v16i8(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_v16i8); }
struct agg_v32i8 va_agg_v32i8(__builtin_va_list l) { return __builtin_va_arg(l, struct agg_v32i8); }
