__attribute__((device)) int read_tid() {
  int x = __nvvm_read_ptx_sreg_tid_x();
  int y = __nvvm_read_ptx_sreg_tid_y();
  int z = __nvvm_read_ptx_sreg_tid_z();
  int w = __nvvm_read_ptx_sreg_tid_w();
  return x + y + z + w;
}
__attribute__((device)) int read_ntid() {
  int x = __nvvm_read_ptx_sreg_ntid_x();
  int y = __nvvm_read_ptx_sreg_ntid_y();
  int z = __nvvm_read_ptx_sreg_ntid_z();
  int w = __nvvm_read_ptx_sreg_ntid_w();
  return x + y + z + w;
}
__attribute__((device)) int read_ctaid() {
  int x = __nvvm_read_ptx_sreg_ctaid_x();
  int y = __nvvm_read_ptx_sreg_ctaid_y();
  int z = __nvvm_read_ptx_sreg_ctaid_z();
  int w = __nvvm_read_ptx_sreg_ctaid_w();
  return x + y + z + w;
}
__attribute__((device)) int read_nctaid() {
  int x = __nvvm_read_ptx_sreg_nctaid_x();
  int y = __nvvm_read_ptx_sreg_nctaid_y();
  int z = __nvvm_read_ptx_sreg_nctaid_z();
  int w = __nvvm_read_ptx_sreg_nctaid_w();
  return x + y + z + w;
}
__attribute__((device)) int read_ids() {
  int a = __nvvm_read_ptx_sreg_laneid();
  int b = __nvvm_read_ptx_sreg_warpid();
  int c = __nvvm_read_ptx_sreg_nwarpid();
  int d = __nvvm_read_ptx_sreg_smid();
  int e = __nvvm_read_ptx_sreg_nsmid();
  int f = __nvvm_read_ptx_sreg_gridid();
  return a + b + c + d + e + f;
}
__attribute__((device)) int read_lanemasks() {
  int a = __nvvm_read_ptx_sreg_lanemask_eq();
  int b = __nvvm_read_ptx_sreg_lanemask_le();
  int c = __nvvm_read_ptx_sreg_lanemask_lt();
  int d = __nvvm_read_ptx_sreg_lanemask_ge();
  int e = __nvvm_read_ptx_sreg_lanemask_gt();
  return a + b + c + d + e;
}
__attribute__((device)) long long read_clocks() {
  int a = __nvvm_read_ptx_sreg_clock();
  long long b = __nvvm_read_ptx_sreg_clock64();
  return a + b;
}
__attribute__((device)) int read_pms() {
  int a = __nvvm_read_ptx_sreg_pm0();
  int b = __nvvm_read_ptx_sreg_pm1();
  int c = __nvvm_read_ptx_sreg_pm2();
  int d = __nvvm_read_ptx_sreg_pm3();
  return a + b + c + d;
}
__attribute__((device)) void sync() {
  __nvvm_bar_sync(0);
}
__attribute__((device)) void nvvm_math(float f1, float f2, double d1, double d2) {
  float t1 = __nvvm_fmax_f(f1, f2);
  float t2 = __nvvm_fmin_f(f1, f2);
  float t3 = __nvvm_sqrt_rn_f(f1);
  float t4 = __nvvm_rcp_rn_f(f2);
  float t5 = __nvvm_add_rn_f(f1, f2);
  double td1 = __nvvm_fmax_d(d1, d2);
  double td2 = __nvvm_fmin_d(d1, d2);
  double td3 = __nvvm_sqrt_rn_d(d1);
  double td4 = __nvvm_rcp_rn_d(d2);
  __nvvm_membar_cta();
  __nvvm_membar_gl();
  __nvvm_membar_sys();
  __syncthreads();
}
__attribute__((device)) int di;
__attribute__((shared)) int si;
__attribute__((device)) long dl;
__attribute__((shared)) long sl;
__attribute__((device)) long long dll;
__attribute__((shared)) long long sll;
__attribute__((device)) void nvvm_atom(float *fp, float f, double *dfp, double df, int *ip,
                          int i, unsigned int *uip, unsigned ui, long *lp,
                          long l, long long *llp, long long ll) {
  __nvvm_atom_add_gen_i(ip, i);
  __nvvm_atom_add_gen_l(&dl, l);
  __nvvm_atom_add_gen_ll(&sll, ll);
  __nvvm_atom_sub_gen_i(ip, i);
  __nvvm_atom_sub_gen_l(&dl, l);
  __nvvm_atom_sub_gen_ll(&sll, ll);
  __nvvm_atom_and_gen_i(ip, i);
  __nvvm_atom_and_gen_l(&dl, l);
  __nvvm_atom_and_gen_ll(&sll, ll);
  __nvvm_atom_or_gen_i(ip, i);
  __nvvm_atom_or_gen_l(&dl, l);
  __nvvm_atom_or_gen_ll(&sll, ll);
  __nvvm_atom_xor_gen_i(ip, i);
  __nvvm_atom_xor_gen_l(&dl, l);
  __nvvm_atom_xor_gen_ll(&sll, ll);
  __nvvm_atom_xchg_gen_i(ip, i);
  __nvvm_atom_xchg_gen_l(&dl, l);
  __nvvm_atom_xchg_gen_ll(&sll, ll);
  __nvvm_atom_max_gen_i(ip, i);
  __nvvm_atom_max_gen_ui((unsigned int *)ip, i);
  __nvvm_atom_max_gen_l(&dl, l);
  __nvvm_atom_max_gen_ul((unsigned long *)&dl, l);
  __nvvm_atom_max_gen_ll(&sll, ll);
  __nvvm_atom_max_gen_ull((unsigned long long *)&sll, ll);
  __nvvm_atom_min_gen_i(ip, i);
  __nvvm_atom_min_gen_ui((unsigned int *)ip, i);
  __nvvm_atom_min_gen_l(&dl, l);
  __nvvm_atom_min_gen_ul((unsigned long *)&dl, l);
  __nvvm_atom_min_gen_ll(&sll, ll);
  __nvvm_atom_min_gen_ull((unsigned long long *)&sll, ll);
  __nvvm_atom_cas_gen_i(ip, 0, i);
  __nvvm_atom_cas_gen_l(&dl, 0, l);
  __nvvm_atom_cas_gen_ll(&sll, 0, ll);
  __nvvm_atom_add_gen_f(fp, f);
  __nvvm_atom_inc_gen_ui(uip, ui);
  __nvvm_atom_dec_gen_ui(uip, ui);
}
__attribute__((device)) void nvvm_ldg(const void *p) {
  __nvvm_ldg_c((const char *)p);
  __nvvm_ldg_uc((const unsigned char *)p);
  __nvvm_ldg_s((const short *)p);
  __nvvm_ldg_us((const unsigned short *)p);
  __nvvm_ldg_i((const int *)p);
  __nvvm_ldg_ui((const unsigned int *)p);
  __nvvm_ldg_l((const long *)p);
  __nvvm_ldg_ul((const unsigned long *)p);
  __nvvm_ldg_f((const float *)p);
  __nvvm_ldg_d((const double *)p);
  typedef char char2 __attribute__((ext_vector_type(2)));
  typedef unsigned char uchar2 __attribute__((ext_vector_type(2)));
  __nvvm_ldg_c2((const char2 *)p);
  __nvvm_ldg_uc2((const uchar2 *)p);
  typedef char char4 __attribute__((ext_vector_type(4)));
  typedef unsigned char uchar4 __attribute__((ext_vector_type(4)));
  __nvvm_ldg_c4((const char4 *)p);
  __nvvm_ldg_uc4((const uchar4 *)p);
  typedef short short2 __attribute__((ext_vector_type(2)));
  typedef unsigned short ushort2 __attribute__((ext_vector_type(2)));
  __nvvm_ldg_s2((const short2 *)p);
  __nvvm_ldg_us2((const ushort2 *)p);
  typedef short short4 __attribute__((ext_vector_type(4)));
  typedef unsigned short ushort4 __attribute__((ext_vector_type(4)));
  __nvvm_ldg_s4((const short4 *)p);
  __nvvm_ldg_us4((const ushort4 *)p);
  typedef int int2 __attribute__((ext_vector_type(2)));
  typedef unsigned int uint2 __attribute__((ext_vector_type(2)));
  __nvvm_ldg_i2((const int2 *)p);
  __nvvm_ldg_ui2((const uint2 *)p);
  typedef int int4 __attribute__((ext_vector_type(4)));
  typedef unsigned int uint4 __attribute__((ext_vector_type(4)));
  __nvvm_ldg_i4((const int4 *)p);
  __nvvm_ldg_ui4((const uint4 *)p);
  typedef long long longlong2 __attribute__((ext_vector_type(2)));
  typedef unsigned long long ulonglong2 __attribute__((ext_vector_type(2)));
  __nvvm_ldg_ll2((const longlong2 *)p);
  __nvvm_ldg_ull2((const ulonglong2 *)p);
  typedef float float2 __attribute__((ext_vector_type(2)));
  __nvvm_ldg_f2((const float2 *)p);
  typedef float float4 __attribute__((ext_vector_type(4)));
  __nvvm_ldg_f4((const float4 *)p);
  typedef double double2 __attribute__((ext_vector_type(2)));
  __nvvm_ldg_d2((const double2 *)p);
}
