float func_p1(float x) { return x; }
double func_p2(double x) { return x; }
long double func_p3(long double x) { return x; }
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
