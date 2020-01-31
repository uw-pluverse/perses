












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

double floor (double);
float floorf (float);
long double floorl (long double);

double ceil (double);
float ceilf (float);
long double ceill (long double);

double round (double);
float roundf (float);
long double roundl (long double);

double rint (double);
float rintf (float);
long double rintl (long double);

int ifloor (double a) { return (int) floor (a); }

int ifloorf (float a) { return (int) floorf (a); }
int ifloorl (long double a) { return (int) floorl (a); }


long lfloor (double a) { return (long) floor (a); }

long lfloorf (float a) { return (long) floorf (a); }
long lfloorl (long double a) { return (long) floorl (a); }


long long llfloor (double a) { return (long long) floor (a); }

long long llfloorf (float a) { return (long long) floorf (a); }
long long llfloorl (long double a) { return (long long) floorl (a); }


int iceil (double a) { return (int) ceil (a); }

int iceilf (float a) { return (int) ceilf (a); }
int iceill (long double a) { return (int) ceill (a); }


long lceil (double a) { return (long) ceil (a); }

long lceilf (float a) { return (long) ceilf (a); }
long lceill (long double a) { return (long) ceill (a); }


long long llceil (double a) { return (long long) ceil (a); }

long long llceilf (float a) { return (long long) ceilf (a); }
long long llceill (long double a) { return (long long) ceill (a); }



int iround (double a) { return (int) round (a); }
int iroundf (float a) { return (int) roundf (a); }
int iroundl (long double a) { return (int) roundl (a); }



int irint (double a) { return (int) rint (a); }
int irintf (float a) { return (int) rintf (a); }
int irintl (long double a) { return (int) rintl (a); }


int main () { return 0; }
