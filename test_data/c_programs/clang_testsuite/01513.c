typedef __attribute__((ext_vector_type(8))) _Bool BoolVector;
typedef __attribute__(( ext_vector_type(2) )) float float2;
typedef __attribute__(( ext_vector_type(3) )) float float3;
typedef __attribute__(( ext_vector_type(4) )) int int4;
typedef __attribute__(( ext_vector_type(8) )) short short8;
typedef __attribute__(( ext_vector_type(4) )) float float4;
typedef float t3 __attribute__ ((vector_size (16)));
typedef __typeof__(sizeof(int)) size_t;
typedef unsigned long ulong2 __attribute__ ((ext_vector_type(2)));
typedef size_t stride4 __attribute__((ext_vector_type(4)));
static void test() {
    float2 vec2;
    float3 vec3;
    float4 vec4, vec4_2;
    int4 ivec4;
    short8 ish8;
    t3 vec4_3;
    int *ptr;
    int i;
    vec3 += vec2;
    vec4 += vec3;
    vec4 = 5.0f;
    vec4 = (float4)5.0f;
    vec4 = (float4)5;
    vec4 = (float4)vec4_3;
    ivec4 = (int4)5.0f;
    ivec4 = (int4)5;
    ivec4 = (int4)vec4_3;
    i = (int)ivec4;
    i = ivec4;
    ivec4 = (int4)ptr;
    vec4 = (float4)vec2;
    ish8 += 5;
    ivec4 *= 5;
     vec4 /= 5.2f;
     vec4 %= 4;
    ivec4 %= 4;
    ivec4 += vec4;
    ivec4 += (int4)vec4;
    ivec4 -= ivec4;
    ivec4 |= ivec4;
    ivec4 += ptr;
}
typedef __attribute__(( ext_vector_type(2) )) float2 vecfloat2;
void inc(float2 f2) {
  f2++;
  __real f2;
}
typedef enum
{
    uchar_stride = 1,
    uchar4_stride = 4,
    ushort4_stride = 8,
    short4_stride = 8,
    uint4_stride = 16,
    int4_stride = 16,
    float4_stride = 16,
} PixelByteStride;
stride4 RDar15091442_get_stride4(int4 x, PixelByteStride pixelByteStride);
stride4 RDar15091442_get_stride4(int4 x, PixelByteStride pixelByteStride)
{
    stride4 stride;
    stride.lo = ((ulong2) x) * pixelByteStride;
    return stride;
}
typedef __attribute__((ext_vector_type(4))) float float32x4_t;
typedef float C3DVector3 __attribute__((ext_vector_type(3)));
extern float32x4_t vabsq_f32(float32x4_t __a);
C3DVector3 Func(const C3DVector3 a) {
    return (C3DVector3)vabsq_f32((float32x4_t)a);
}
typedef double double2 __attribute__ ((ext_vector_type(2)));
static void splats(int i, long l, __uint128_t t, float f, double d) {
  short8 vs = 0;
  int4 vi = i;
  ulong2 vl = (unsigned long)l;
  float2 vf = f;
  double2 vd = d;
  vs = 65536 + vs;
  vs = vs + i;
  vs = vs + 1;
  vs = vs + 1.f;
  vi = l + vi;
  vi = 1 + vi;
  vi = vi + 2.0;
  vi = vi + 0xffffffff;
  vl = l + vl;
  vl = vl + t;
  vf = 1 + vf;
  vf = l + vf;
  vf = 2.0 + vf;
  vf = d + vf;
  vf = vf + 0xffffffff;
  vf = vf + 2.1;
  vd = l + vd;
  vd = vd + t;
}
