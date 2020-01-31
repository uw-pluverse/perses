typedef double float64x1_t __attribute__ ((__vector_size__ (sizeof (double)))); float64x1_t test_vadd_f64 (float64x1_t a, float64x1_t b) { return a + b; } void test_f64 (double val) { float64x1_t var = { val }; double v0 = var[0]; double v1 = var[1]; }




typedef long long int64x1_t __attribute__ ((__vector_size__ (sizeof (long long)))); int64x1_t test_vadd_s64 (int64x1_t a, int64x1_t b) { return a + b; } void test_s64 (long long val) { int64x1_t var = { val }; long long v0 = var[0]; long long v1 = var[1]; }

typedef float float32x1_t __attribute__ ((__vector_size__ (sizeof (float)))); float32x1_t test_vadd_f32 (float32x1_t a, float32x1_t b) { return a + b; } void test_f32 (float val) { float32x1_t var = { val }; float v0 = var[0]; float v1 = var[1]; }

typedef long longx1_t __attribute__ ((__vector_size__ (sizeof (long)))); longx1_t test_vadd_l (longx1_t a, longx1_t b) { return a + b; } void test_l (long val) { longx1_t var = { val }; long v0 = var[0]; long v1 = var[1]; }

typedef int intx1_t __attribute__ ((__vector_size__ (sizeof (int)))); intx1_t test_vadd_i (intx1_t a, intx1_t b) { return a + b; } void test_i (int val) { intx1_t var = { val }; int v0 = var[0]; int v1 = var[1]; }

typedef short int16x1_t __attribute__ ((__vector_size__ (sizeof (short)))); int16x1_t test_vadd_s16 (int16x1_t a, int16x1_t b) { return a + b; } void test_s16 (short val) { int16x1_t var = { val }; short v0 = var[0]; short v1 = var[1]; }

typedef char int8x1_t __attribute__ ((__vector_size__ (sizeof (char)))); int8x1_t test_vadd_s8 (int8x1_t a, int8x1_t b) { return a + b; } void test_s8 (char val) { int8x1_t var = { val }; char v0 = var[0]; char v1 = var[1]; }
