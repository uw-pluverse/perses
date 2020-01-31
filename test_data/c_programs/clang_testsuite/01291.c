typedef __attribute__(( ext_vector_type(2) )) float float2;
typedef __attribute__(( ext_vector_type(3) )) float float3;
typedef __attribute__(( ext_vector_type(4) )) float float4;
typedef __attribute__(( ext_vector_type(16) )) float float16;
static float4 vec4_0 = (float4)0.5f;
static void test() {
    float2 vec2, vec2_2;
    float3 vec3;
    float4 vec4, vec4_2, *vec4p;
    float16 vec16;
    float f;
    vec2.z;
    vec2.xyzw;
    vec4.xyzw;
    vec4.xyzc;
    vec4.s01z;
    vec2 = vec4.s01;
    vec2 = vec4.S01;
    vec3 = vec4.xyz;
    f = vec2.x;
    f = vec4.xy.x;
    vec4_2.xyzx = vec4.xyzw;
    vec4_2.xyzz = vec4.xyzw;
    vec4_2.xyyw = vec4.xyzw;
    vec2.x = f;
    vec2.xx = vec2_2.xy;
    vec2.yx = vec2_2.xy;
    vec4 = (float4){ 1,2,3,4 };
    vec4.xy.w;
    vec4.s06;
    vec4.x = vec16.sf;
    vec4.x = vec16.sF;
    vec4p->yz = vec4p->xy;
    vec2.a;
    vec2.rgba;
    vec4.rgba;
    vec4.rgbz;
    vec4.rgbc;
    vec4.xyzr;
    vec4.s01b;
    vec3 = vec4.rgb;
    f = vec2.r;
    f = vec4.rg.r;
    vec4_2.rgba = vec4.xyzw;
    vec4_2.rgbr = vec4.rgba;
    vec4_2.rgbb = vec4.rgba;
    vec4_2.rgga = vec4.rgba;
    vec2.x = f;
    vec2.rr = vec2_2.rg;
    vec2.gr = vec2_2.rg;
    vec2.gr.g = vec2_2.r;
    vec4 = (float4){ 1,2,3,4 };
    vec4.rg.b;
    vec4.r = vec16.sf;
    vec4.g = vec16.sF;
    vec4p->gb = vec4p->rg;
}
float2 lo(float3 x) { return x.lo; }
float2 hi(float3 x) { return x.hi; }
float2 ev(float3 x) { return x.even; }
float2 od(float3 x) { return x.odd; }
