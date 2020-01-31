struct f1 { float f[1]; };
struct f2 { float f[2]; };
struct f3 { float f[3]; };
struct f4 { float f[4]; };
struct f5 { float f[5]; };
struct f6 { float f[6]; };
struct f7 { float f[7]; };
struct f8 { float f[8]; };
struct f9 { float f[9]; };
struct fab { float a; float b; };
struct fabc { float a; float b; float c; };
struct f2a2b { float a[2]; float b[2]; };
struct f1 func_f1(struct f1 x) { return x; }
struct f2 func_f2(struct f2 x) { return x; }
struct f3 func_f3(struct f3 x) { return x; }
struct f4 func_f4(struct f4 x) { return x; }
struct f5 func_f5(struct f5 x) { return x; }
struct f6 func_f6(struct f6 x) { return x; }
struct f7 func_f7(struct f7 x) { return x; }
struct f8 func_f8(struct f8 x) { return x; }
struct f9 func_f9(struct f9 x) { return x; }
struct fab func_fab(struct fab x) { return x; }
struct fabc func_fabc(struct fabc x) { return x; }
struct f2a2b func_f2a2b(struct f2a2b x) { return x; }
struct f1 global_f1;
void call_f1(void) { global_f1 = func_f1(global_f1); }
struct f2 global_f2;
void call_f2(void) { global_f2 = func_f2(global_f2); }
struct f3 global_f3;
void call_f3(void) { global_f3 = func_f3(global_f3); }
struct f4 global_f4;
void call_f4(void) { global_f4 = func_f4(global_f4); }
struct f5 global_f5;
void call_f5(void) { global_f5 = func_f5(global_f5); }
struct f6 global_f6;
void call_f6(void) { global_f6 = func_f6(global_f6); }
struct f7 global_f7;
void call_f7(void) { global_f7 = func_f7(global_f7); }
struct f8 global_f8;
void call_f8(void) { global_f8 = func_f8(global_f8); }
struct f9 global_f9;
void call_f9(void) { global_f9 = func_f9(global_f9); }
struct fab global_fab;
void call_fab(void) { global_fab = func_fab(global_fab); }
struct fabc global_fabc;
void call_fabc(void) { global_fabc = func_fabc(global_fabc); }
struct v1 { vector int v[1]; };
struct v2 { vector int v[2]; };
struct v3 { vector int v[3]; };
struct v4 { vector int v[4]; };
struct v5 { vector int v[5]; };
struct v6 { vector int v[6]; };
struct v7 { vector int v[7]; };
struct v8 { vector int v[8]; };
struct v9 { vector int v[9]; };
struct vab { vector int a; vector int b; };
struct vabc { vector int a; vector int b; vector int c; };
struct v1 func_v1(struct v1 x) { return x; }
struct v2 func_v2(struct v2 x) { return x; }
struct v3 func_v3(struct v3 x) { return x; }
struct v4 func_v4(struct v4 x) { return x; }
struct v5 func_v5(struct v5 x) { return x; }
struct v6 func_v6(struct v6 x) { return x; }
struct v7 func_v7(struct v7 x) { return x; }
struct v8 func_v8(struct v8 x) { return x; }
struct v9 func_v9(struct v9 x) { return x; }
struct vab func_vab(struct vab x) { return x; }
struct vabc func_vabc(struct vabc x) { return x; }
struct v1 global_v1;
void call_v1(void) { global_v1 = func_v1(global_v1); }
struct v2 global_v2;
void call_v2(void) { global_v2 = func_v2(global_v2); }
struct v3 global_v3;
void call_v3(void) { global_v3 = func_v3(global_v3); }
struct v4 global_v4;
void call_v4(void) { global_v4 = func_v4(global_v4); }
struct v5 global_v5;
void call_v5(void) { global_v5 = func_v5(global_v5); }
struct v6 global_v6;
void call_v6(void) { global_v6 = func_v6(global_v6); }
struct v7 global_v7;
void call_v7(void) { global_v7 = func_v7(global_v7); }
struct v8 global_v8;
void call_v8(void) { global_v8 = func_v8(global_v8); }
struct v9 global_v9;
void call_v9(void) { global_v9 = func_v9(global_v9); }
struct vab global_vab;
void call_vab(void) { global_vab = func_vab(global_vab); }
struct vabc global_vabc;
void call_vabc(void) { global_vabc = func_vabc(global_vabc); }
typedef float float3 __attribute__((vector_size (12)));
struct v3f1 { float3 v[1]; };
struct v3f2 { float3 v[2]; };
struct v3f3 { float3 v[3]; };
struct v3f4 { float3 v[4]; };
struct v3f5 { float3 v[5]; };
struct v3f6 { float3 v[6]; };
struct v3f7 { float3 v[7]; };
struct v3f8 { float3 v[8]; };
struct v3f9 { float3 v[9]; };
struct v3fab { float3 a; float3 b; };
struct v3fabc { float3 a; float3 b; float3 c; };
struct v3f1 func_v3f1(struct v3f1 x) { return x; }
struct v3f2 func_v3f2(struct v3f2 x) { return x; }
struct v3f3 func_v3f3(struct v3f3 x) { return x; }
struct v3f4 func_v3f4(struct v3f4 x) { return x; }
struct v3f5 func_v3f5(struct v3f5 x) { return x; }
struct v3f6 func_v3f6(struct v3f6 x) { return x; }
struct v3f7 func_v3f7(struct v3f7 x) { return x; }
struct v3f8 func_v3f8(struct v3f8 x) { return x; }
struct v3f9 func_v3f9(struct v3f9 x) { return x; }
struct v3fab func_v3fab(struct v3fab x) { return x; }
struct v3fabc func_v3fabc(struct v3fabc x) { return x; }
struct v3f1 global_v3f1;
void call_v3f1(void) { global_v3f1 = func_v3f1(global_v3f1); }
struct v3f2 global_v3f2;
void call_v3f2(void) { global_v3f2 = func_v3f2(global_v3f2); }
struct v3f3 global_v3f3;
void call_v3f3(void) { global_v3f3 = func_v3f3(global_v3f3); }
struct v3f4 global_v3f4;
void call_v3f4(void) { global_v3f4 = func_v3f4(global_v3f4); }
struct v3f5 global_v3f5;
void call_v3f5(void) { global_v3f5 = func_v3f5(global_v3f5); }
struct v3f6 global_v3f6;
void call_v3f6(void) { global_v3f6 = func_v3f6(global_v3f6); }
struct v3f7 global_v3f7;
void call_v3f7(void) { global_v3f7 = func_v3f7(global_v3f7); }
struct v3f8 global_v3f8;
void call_v3f8(void) { global_v3f8 = func_v3f8(global_v3f8); }
struct v3f9 global_v3f9;
void call_v3f9(void) { global_v3f9 = func_v3f9(global_v3f9); }
struct v3fab global_v3fab;
void call_v3fab(void) { global_v3fab = func_v3fab(global_v3fab); }
struct v3fabc global_v3fabc;
void call_v3fabc(void) { global_v3fabc = func_v3fabc(global_v3fabc); }
struct s1 { char c[1]; };
struct s2 { char c[2]; };
struct s3 { char c[3]; };
struct s4 { char c[4]; };
struct s5 { char c[5]; };
struct s6 { char c[6]; };
struct s7 { char c[7]; };
struct s8 { char c[8]; };
struct s9 { char c[9]; };
struct s16 { char c[16]; };
struct s17 { char c[17]; };
struct s1 ret_s1() {
  return (struct s1) { 17 };
}
struct s2 ret_s2() {
  return (struct s2) { 17, 18 };
}
struct s3 ret_s3() {
  return (struct s3) { 17, 18, 19 };
}
struct s4 ret_s4() {
  return (struct s4) { 17, 18, 19, 20 };
}
struct s5 ret_s5() {
  return (struct s5) { 17, 18, 19, 20, 21 };
}
struct s6 ret_s6() {
  return (struct s6) { 17, 18, 19, 20, 21, 22 };
}
struct s7 ret_s7() {
  return (struct s7) { 17, 18, 19, 20, 21, 22, 23 };
}
struct s8 ret_s8() {
  return (struct s8) { 17, 18, 19, 20, 21, 22, 23, 24 };
}
struct s9 ret_s9() {
  return (struct s9) { 17, 18, 19, 20, 21, 22, 23, 24, 25 };
}
struct s16 ret_s16() {
  return (struct s16) { 17, 18, 19, 20, 21, 22, 23, 24,
                        25, 26, 27, 28, 29, 30, 31, 32 };
}
struct s17 ret_s17() {
  return (struct s17) { 17, 18, 19, 20, 21, 22, 23, 24,
                        25, 26, 27, 28, 29, 30, 31, 32, 33 };
}
