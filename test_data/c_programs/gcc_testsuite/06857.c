




typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;







typedef long int __quad_t;
typedef unsigned long int __u_quad_t;


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;
typedef __loff_t loff_t;



typedef __ino_t ino_t;
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
typedef __pid_t pid_t;
typedef __ssize_t ssize_t;
typedef __time_t time_t;
typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
typedef long unsigned int size_t;
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
extern double fabs(double); extern float fabsf(float); extern long double fabsl(long double);
extern double sqrt(double); extern float sqrtf(float); extern long double sqrtl(long double);
extern double cbrt(double); extern float cbrtf(float); extern long double cbrtl(long double);
extern double pow(double, double); extern float powf(float, float); extern long double powl(long double, long double);

void test(double d1, double d2, double d3,
   float f1, float f2, float f3,
   long double ld1, long double ld2, long double ld3)
{
  extern void link_failure_sqrt_sqrt(void); if (sqrt(sqrt((d1))) != pow((d1),1.0/(2*2)) || sqrtf(sqrtf((f1))) != powf((f1),1.0F/(2*2)) || sqrtl(sqrtl((ld1))) != powl((ld1),1.0L/(2*2))) link_failure_sqrt_sqrt();
  extern void link_failure_sqrt_cbrt(void); if (sqrt(cbrt((d1))) != pow((d1),1.0/(2*3)) || sqrtf(cbrtf((f1))) != powf((f1),1.0F/(2*3)) || sqrtl(cbrtl((ld1))) != powl((ld1),1.0L/(2*3))) link_failure_sqrt_cbrt();
  extern void link_failure_cbrt_sqrt(void); if (cbrt(sqrt((d1))) != pow((d1),1.0/(3*2)) || cbrtf(sqrtf((f1))) != powf((f1),1.0F/(3*2)) || cbrtl(sqrtl((ld1))) != powl((ld1),1.0L/(3*2))) link_failure_cbrt_sqrt();
  extern void link_failure_cbrt_cbrt(void); if (cbrt(cbrt(fabs(d1))) != pow(fabs(d1),1.0/(3*3)) || cbrtf(cbrtf(fabs(f1))) != powf(fabs(f1),1.0F/(3*3)) || cbrtl(cbrtl(fabs(ld1))) != powl(fabs(ld1),1.0L/(3*3))) link_failure_cbrt_cbrt();
  extern void link_failure_pow_sqrt(void); if (pow(sqrt((d1)), d2) != pow((d1),d2/2) || powf(sqrtf((f1)),f2) != powf((f1),f2/2) || powl(sqrtl((ld1)),ld2) != powl((ld1),ld2/2)) link_failure_pow_sqrt();
  extern void link_failure_pow_cbrt(void); if (pow(cbrt(fabs(d1)), d2) != pow(fabs(d1),d2/3) || powf(cbrtf(fabs(f1)),f2) != powf(fabs(f1),f2/3) || powl(cbrtl(fabs(ld1)),ld2) != powl(fabs(ld1),ld2/3)) link_failure_pow_cbrt();
  extern void link_failure_sqrt_pow(void); if (sqrt(pow(fabs(d1), d2)) != pow(fabs(d1),d2/2) || sqrtf(powf(fabs(f1),f2)) != powf(fabs(f1),f2/2) || sqrtl(powl(fabs(ld1),ld2)) != powl(fabs(ld1),ld2/2)) link_failure_sqrt_pow();
  extern void link_failure_cbrt_pow(void); if (cbrt(pow(fabs(d1), d2)) != pow(fabs(d1),d2/3) || cbrtf(powf(fabs(f1),f2)) != powf(fabs(f1),f2/3) || cbrtl(powl(fabs(ld1),ld2)) != powl(fabs(ld1),ld2/3)) link_failure_cbrt_pow();
  extern void link_failure_pow_pow(void); if (pow(pow(fabs(d1), d2), d3) != pow(fabs(d1),d2*d3) || powf(powf(fabs(f1),f2),f3) != powf(fabs(f1),f2*f3) || powl(powl(fabs(ld1),ld2),ld3) != powl(fabs(ld1),ld2*ld3)) link_failure_pow_pow();
  extern void link_failure_root_x_root(void); if (sqrt(d1)*sqrt(d2) != sqrt(d1*d2) || sqrtf(f1)*sqrtf(f2) != sqrtf(f1*f2) || sqrtl(ld1)*sqrtl(ld2) != sqrtl(ld1*ld2)) link_failure_root_x_root();
  extern void link_failure_root_x_root(void); if (cbrt(d1)*cbrt(d2) != cbrt(d1*d2) || cbrtf(f1)*cbrtf(f2) != cbrtf(f1*f2) || cbrtl(ld1)*cbrtl(ld2) != cbrtl(ld1*ld2)) link_failure_root_x_root();
  extern void link_failure_pow_x_pow(void); if (pow(d1,d2)*pow(d1,d3) != pow(d1,d2+d3) || powf(f1,f2)*powf(f1,f3) != powf(f1,f2+f3) || powl(ld1,ld2)*powl(ld1,ld3) != powl(ld1,ld2+ld3)) link_failure_pow_x_pow();

}

int main (void)
{
  return 0;
}
