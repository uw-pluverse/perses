float f0(float x, float y, float z) { return __builtin_fmaf(x,y,z); }
float f1(float x, float y, float z) { return __builtin_fmaf(x,y,-z); }
float f2(float x, float y, float z) { return __builtin_fmaf(-x,y,z); }
float f3(float x, float y, float z) { return __builtin_fmaf(x,-y,z); }
float f4(float x, float y, float z) { return __builtin_fmaf(-x,-y,z); }

double d0(double x, double y, double z) { return __builtin_fma(x,y,z); }
double d1(double x, double y, double z) { return __builtin_fma(x,y,-z); }
double d2(double x, double y, double z) { return __builtin_fma(-x,y,z); }
double d3(double x, double y, double z) { return __builtin_fma(x,-y,z); }
double d4(double x, double y, double z) { return __builtin_fma(-x,-y,z); }
