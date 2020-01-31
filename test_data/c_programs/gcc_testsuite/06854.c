extern double exp(double); extern float expf(float); extern long double expl(long double);
extern double exp2(double); extern float exp2f(float); extern long double exp2l(long double);
extern double exp10(double); extern float exp10f(float); extern long double exp10l(long double);
extern double log(double); extern float logf(float); extern long double logl(long double);
extern double log2(double); extern float log2f(float); extern long double log2l(long double);
extern double log10(double); extern float log10f(float); extern long double log10l(long double);
extern double pow10(double); extern float pow10f(float); extern long double pow10l(long double);
extern double sqrt(double); extern float sqrtf(float); extern long double sqrtl(long double);
extern double cbrt(double); extern float cbrtf(float); extern long double cbrtl(long double);
extern double pow(double, double); extern float powf(float, float); extern long double powl(long double, long double);

void test(double d1, double d2, float f1, float f2,
   long double ld1, long double ld2)
{






  extern void link_failure_log_1(void); if (log(1.0) != 0.0 || logf(1.0F) != 0.0F || logl(1.0L) != 0.0L) link_failure_log_1();
  extern void link_failure_log2_1(void); if (log2(1.0) != 0.0 || log2f(1.0F) != 0.0F || log2l(1.0L) != 0.0L) link_failure_log2_1();
  extern void link_failure_log10_1(void); if (log10(1.0) != 0.0 || log10f(1.0F) != 0.0F || log10l(1.0L) != 0.0L) link_failure_log10_1();







  extern void link_failure_log2_N(void); if (log2(2.0) != 1.0 || log2f( 2.0F) != 1.0F || log2l( 2.0L) != 1.0L) link_failure_log2_N();
  extern void link_failure_log10_N(void); if (log10(10.0) != 1.0 || log10f( 10.0F) != 1.0F || log10l( 10.0L) != 1.0L) link_failure_log10_N();







  extern void link_failure_log_exp_same(void); if (log(exp(d1)) != d1 || logf(expf(f1)) != f1 || logl(expl(ld1)) != ld1) link_failure_log_exp_same();
  extern void link_failure_log2_exp2_same(void); if (log2(exp2(d1)) != d1 || log2f(exp2f(f1)) != f1 || log2l(exp2l(ld1)) != ld1) link_failure_log2_exp2_same();
  extern void link_failure_log10_exp10_same(void); if (log10(exp10(d1)) != d1 || log10f(exp10f(f1)) != f1 || log10l(exp10l(ld1)) != ld1) link_failure_log10_exp10_same();
  extern void link_failure_log10_pow10_same(void); if (log10(pow10(d1)) != d1 || log10f(pow10f(f1)) != f1 || log10l(pow10l(ld1)) != ld1) link_failure_log10_pow10_same();







  extern void link_failure_log_exp2(void); if (log(exp2(d1)) != d1*log(2.0) || logf(exp2f(f1)) != f1*logf(2.0F) || logl(exp2l(ld1)) != ld1*logl(2.0L)) link_failure_log_exp2();
  extern void link_failure_log_exp10(void); if (log(exp10(d1)) != d1*log(10.0) || logf(exp10f(f1)) != f1*logf(10.0F) || logl(exp10l(ld1)) != ld1*logl(10.0L)) link_failure_log_exp10();
  extern void link_failure_log_pow10(void); if (log(pow10(d1)) != d1*log(10.0) || logf(pow10f(f1)) != f1*logf(10.0F) || logl(pow10l(ld1)) != ld1*logl(10.0L)) link_failure_log_pow10();
  extern void link_failure_log2_exp(void); if (log2(exp(d1)) != d1*log2(2.7182818284590452353602874713526624977572470936999595749669676277241) || log2f(expf(f1)) != f1*log2f(2.7182818284590452353602874713526624977572470936999595749669676277241F) || log2l(expl(ld1)) != ld1*log2l(2.7182818284590452353602874713526624977572470936999595749669676277241L)) link_failure_log2_exp();
  extern void link_failure_log2_exp2(void); if (log2(exp2(d1)) != d1*log2(2.0) || log2f(exp2f(f1)) != f1*log2f(2.0F) || log2l(exp2l(ld1)) != ld1*log2l(2.0L)) link_failure_log2_exp2();
  extern void link_failure_log2_exp10(void); if (log2(exp10(d1)) != d1*log2(10.0) || log2f(exp10f(f1)) != f1*log2f(10.0F) || log2l(exp10l(ld1)) != ld1*log2l(10.0L)) link_failure_log2_exp10();
  extern void link_failure_log2_pow10(void); if (log2(pow10(d1)) != d1*log2(10.0) || log2f(pow10f(f1)) != f1*log2f(10.0F) || log2l(pow10l(ld1)) != ld1*log2l(10.0L)) link_failure_log2_pow10();
  extern void link_failure_log10_exp(void); if (log10(exp(d1)) != d1*log10(2.7182818284590452353602874713526624977572470936999595749669676277241) || log10f(expf(f1)) != f1*log10f(2.7182818284590452353602874713526624977572470936999595749669676277241F) || log10l(expl(ld1)) != ld1*log10l(2.7182818284590452353602874713526624977572470936999595749669676277241L)) link_failure_log10_exp();
  extern void link_failure_log10_exp2(void); if (log10(exp2(d1)) != d1*log10(2.0) || log10f(exp2f(f1)) != f1*log10f(2.0F) || log10l(exp2l(ld1)) != ld1*log10l(2.0L)) link_failure_log10_exp2();
  extern void link_failure_log10_exp10(void); if (log10(exp10(d1)) != d1*log10(10.0) || log10f(exp10f(f1)) != f1*log10f(10.0F) || log10l(exp10l(ld1)) != ld1*log10l(10.0L)) link_failure_log10_exp10();
  extern void link_failure_log10_pow10(void); if (log10(pow10(d1)) != d1*log10(10.0) || log10f(pow10f(f1)) != f1*log10f(10.0F) || log10l(pow10l(ld1)) != ld1*log10l(10.0L)) link_failure_log10_pow10();







  extern void link_failure_log_sqrt(void); if (log(sqrt(d1)) != 0.5*log(d1) || logf(sqrtf(f1)) != 0.5F*logf(f1) || logl(sqrtl(ld1)) != 0.5L*logl(ld1)) link_failure_log_sqrt();
  extern void link_failure_log2_sqrt(void); if (log2(sqrt(d1)) != 0.5*log2(d1) || log2f(sqrtf(f1)) != 0.5F*log2f(f1) || log2l(sqrtl(ld1)) != 0.5L*log2l(ld1)) link_failure_log2_sqrt();
  extern void link_failure_log10_sqrt(void); if (log10(sqrt(d1)) != 0.5*log10(d1) || log10f(sqrtf(f1)) != 0.5F*log10f(f1) || log10l(sqrtl(ld1)) != 0.5L*log10l(ld1)) link_failure_log10_sqrt();







  extern void link_failure_sqrt_exp(void); if (sqrt(exp(d1)) != exp(d1*0.5) || sqrtf(expf(f1)) != expf(f1*0.5F) || sqrtl(expl(ld1)) != expl(ld1*0.5L)) link_failure_sqrt_exp();
  extern void link_failure_sqrt_exp2(void); if (sqrt(exp2(d1)) != exp2(d1*0.5) || sqrtf(exp2f(f1)) != exp2f(f1*0.5F) || sqrtl(exp2l(ld1)) != exp2l(ld1*0.5L)) link_failure_sqrt_exp2();
  extern void link_failure_sqrt_exp10(void); if (sqrt(exp10(d1)) != exp10(d1*0.5) || sqrtf(exp10f(f1)) != exp10f(f1*0.5F) || sqrtl(exp10l(ld1)) != exp10l(ld1*0.5L)) link_failure_sqrt_exp10();
  extern void link_failure_sqrt_pow10(void); if (sqrt(pow10(d1)) != pow10(d1*0.5) || sqrtf(pow10f(f1)) != pow10f(f1*0.5F) || sqrtl(pow10l(ld1)) != pow10l(ld1*0.5L)) link_failure_sqrt_pow10();
  extern void link_failure_log_cbrt(void); if (log(cbrt(d1)) != (1.0/3)*log(d1) || logf(cbrtf(f1)) != (1.0F/3)*logf(f1) || logl(cbrtl(ld1)) != (1.0L/3)*logl(ld1)) link_failure_log_cbrt();
  extern void link_failure_log2_cbrt(void); if (log2(cbrt(d1)) != (1.0/3)*log2(d1) || log2f(cbrtf(f1)) != (1.0F/3)*log2f(f1) || log2l(cbrtl(ld1)) != (1.0L/3)*log2l(ld1)) link_failure_log2_cbrt();
  extern void link_failure_log10_cbrt(void); if (log10(cbrt(d1)) != (1.0/3)*log10(d1) || log10f(cbrtf(f1)) != (1.0F/3)*log10f(f1) || log10l(cbrtl(ld1)) != (1.0L/3)*log10l(ld1)) link_failure_log10_cbrt();







  extern void link_failure_cbrt_exp(void); if (cbrt(exp(d1)) != exp(d1/3.0) || cbrtf(expf(f1)) != expf(f1/3.0F) || cbrtl(expl(ld1)) != expl(ld1/3.0L)) link_failure_cbrt_exp();
  extern void link_failure_cbrt_exp2(void); if (cbrt(exp2(d1)) != exp2(d1/3.0) || cbrtf(exp2f(f1)) != exp2f(f1/3.0F) || cbrtl(exp2l(ld1)) != exp2l(ld1/3.0L)) link_failure_cbrt_exp2();
  extern void link_failure_cbrt_exp10(void); if (cbrt(exp10(d1)) != exp10(d1/3.0) || cbrtf(exp10f(f1)) != exp10f(f1/3.0F) || cbrtl(exp10l(ld1)) != exp10l(ld1/3.0L)) link_failure_cbrt_exp10();
  extern void link_failure_cbrt_pow10(void); if (cbrt(pow10(d1)) != pow10(d1/3.0) || cbrtf(pow10f(f1)) != pow10f(f1/3.0F) || cbrtl(pow10l(ld1)) != pow10l(ld1/3.0L)) link_failure_cbrt_pow10();







  extern void link_failure_log_pow(void); if (log(pow(d1,d2)) != d2*log(d1) || logf(powf(f1,f2)) != f2*logf(f1) || logl(powl(ld1,ld2)) != ld2*logl(ld1)) link_failure_log_pow();
  extern void link_failure_log2_pow(void); if (log2(pow(d1,d2)) != d2*log2(d1) || log2f(powf(f1,f2)) != f2*log2f(f1) || log2l(powl(ld1,ld2)) != ld2*log2l(ld1)) link_failure_log2_pow();
  extern void link_failure_log10_pow(void); if (log10(pow(d1,d2)) != d2*log10(d1) || log10f(powf(f1,f2)) != f2*log10f(f1) || log10l(powl(ld1,ld2)) != ld2*log10l(ld1)) link_failure_log10_pow();







  extern void link_failure_pow_exp(void); if (pow(exp(d1),d2) != exp(d1*d2) || powf( expf(f1),f2) != expf(f1*f2) || powl( expl(ld1),ld2) != expl(ld1*ld2)) link_failure_pow_exp();
  extern void link_failure_pow_exp2(void); if (pow(exp2(d1),d2) != exp2(d1*d2) || powf( exp2f(f1),f2) != exp2f(f1*f2) || powl( exp2l(ld1),ld2) != exp2l(ld1*ld2)) link_failure_pow_exp2();
  extern void link_failure_pow_exp10(void); if (pow(exp10(d1),d2) != exp10(d1*d2) || powf( exp10f(f1),f2) != exp10f(f1*f2) || powl( exp10l(ld1),ld2) != exp10l(ld1*ld2)) link_failure_pow_exp10();
  extern void link_failure_pow_pow10(void); if (pow(pow10(d1),d2) != pow10(d1*d2) || powf( pow10f(f1),f2) != pow10f(f1*f2) || powl( pow10l(ld1),ld2) != pow10l(ld1*ld2)) link_failure_pow_pow10();







  extern void link_failure_exp_0(void); if (exp(0.0) != 1.0 || expf(0.0F) != 1.0F || expl(0.0L) != 1.0L) link_failure_exp_0();
  extern void link_failure_exp2_0(void); if (exp2(0.0) != 1.0 || exp2f(0.0F) != 1.0F || exp2l(0.0L) != 1.0L) link_failure_exp2_0();
  extern void link_failure_exp10_0(void); if (exp10(0.0) != 1.0 || exp10f(0.0F) != 1.0F || exp10l(0.0L) != 1.0L) link_failure_exp10_0();
  extern void link_failure_pow10_0(void); if (pow10(0.0) != 1.0 || pow10f(0.0F) != 1.0F || pow10l(0.0L) != 1.0L) link_failure_pow10_0();







  extern void link_failure_exp_N(void); if (exp(1.0) != 2.7182818284590452353602874713526624977572470936999595749669676277241 || expf(1.0F) != 2.7182818284590452353602874713526624977572470936999595749669676277241F || expl(1.0L) != 2.7182818284590452353602874713526624977572470936999595749669676277241L) link_failure_exp_N();
  extern void link_failure_exp2_N(void); if (exp2(1.0) != 2.0 || exp2f(1.0F) != 2.0F || exp2l(1.0L) != 2.0L) link_failure_exp2_N();
  extern void link_failure_exp10_N(void); if (exp10(1.0) != 10.0 || exp10f(1.0F) != 10.0F || exp10l(1.0L) != 10.0L) link_failure_exp10_N();
  extern void link_failure_pow10_N(void); if (pow10(1.0) != 10.0 || pow10f(1.0F) != 10.0F || pow10l(1.0L) != 10.0L) link_failure_pow10_N();
  extern void link_failure_exp_INT(void); if (exp(5.0) < (2.7182818284590452353602874713526624977572470936999595749669676277241)*(2.7182818284590452353602874713526624977572470936999595749669676277241)*(2.7182818284590452353602874713526624977572470936999595749669676277241)*(2.7182818284590452353602874713526624977572470936999595749669676277241)*(2.7182818284590452353602874713526624977572470936999595749669676277241) - (sizeof (float) < sizeof (double) ? 0.0000001 : 0.0001F) || exp(5.0) > (2.7182818284590452353602874713526624977572470936999595749669676277241)*(2.7182818284590452353602874713526624977572470936999595749669676277241)*(2.7182818284590452353602874713526624977572470936999595749669676277241)*(2.7182818284590452353602874713526624977572470936999595749669676277241)*(2.7182818284590452353602874713526624977572470936999595749669676277241) + (sizeof (float) < sizeof (double) ? 0.0000001 : 0.0001F) || expf(5.0F) < ( 2.7182818284590452353602874713526624977572470936999595749669676277241F)*( 2.7182818284590452353602874713526624977572470936999595749669676277241F)*( 2.7182818284590452353602874713526624977572470936999595749669676277241F)*( 2.7182818284590452353602874713526624977572470936999595749669676277241F)*( 2.7182818284590452353602874713526624977572470936999595749669676277241F) -0.0001F || expf(5.0F) > ( 2.7182818284590452353602874713526624977572470936999595749669676277241F)*( 2.7182818284590452353602874713526624977572470936999595749669676277241F)*( 2.7182818284590452353602874713526624977572470936999595749669676277241F)*( 2.7182818284590452353602874713526624977572470936999595749669676277241F)*( 2.7182818284590452353602874713526624977572470936999595749669676277241F) +0.0001F || expl(5.0L) < ( 2.7182818284590452353602874713526624977572470936999595749669676277241L)*( 2.7182818284590452353602874713526624977572470936999595749669676277241L)*( 2.7182818284590452353602874713526624977572470936999595749669676277241L)*( 2.7182818284590452353602874713526624977572470936999595749669676277241L)*( 2.7182818284590452353602874713526624977572470936999595749669676277241L) -(sizeof (float) < sizeof (long double) ? 0.0000000000001L : 0.0001F) || expl(5.0L) > ( 2.7182818284590452353602874713526624977572470936999595749669676277241L)*( 2.7182818284590452353602874713526624977572470936999595749669676277241L)*( 2.7182818284590452353602874713526624977572470936999595749669676277241L)*( 2.7182818284590452353602874713526624977572470936999595749669676277241L)*( 2.7182818284590452353602874713526624977572470936999595749669676277241L) +(sizeof (float) < sizeof (long double) ? 0.0000000000001L : 0.0001F)) link_failure_exp_INT();
  extern void link_failure_exp2_INT(void); if (exp2(5.0) < (2.0)*(2.0)*(2.0)*(2.0)*(2.0) - (sizeof (float) < sizeof (double) ? 0.0000001 : 0.0001F) || exp2(5.0) > (2.0)*(2.0)*(2.0)*(2.0)*(2.0) + (sizeof (float) < sizeof (double) ? 0.0000001 : 0.0001F) || exp2f(5.0F) < ( 2.0F)*( 2.0F)*( 2.0F)*( 2.0F)*( 2.0F) -0.0001F || exp2f(5.0F) > ( 2.0F)*( 2.0F)*( 2.0F)*( 2.0F)*( 2.0F) +0.0001F || exp2l(5.0L) < ( 2.0L)*( 2.0L)*( 2.0L)*( 2.0L)*( 2.0L) -(sizeof (float) < sizeof (long double) ? 0.0000000000001L : 0.0001F) || exp2l(5.0L) > ( 2.0L)*( 2.0L)*( 2.0L)*( 2.0L)*( 2.0L) +(sizeof (float) < sizeof (long double) ? 0.0000000000001L : 0.0001F)) link_failure_exp2_INT();
  extern void link_failure_exp10_INT(void); if (exp10(5.0) < (10.0)*(10.0)*(10.0)*(10.0)*(10.0) - (sizeof (float) < sizeof (double) ? 0.0000001 : 0.0001F) || exp10(5.0) > (10.0)*(10.0)*(10.0)*(10.0)*(10.0) + (sizeof (float) < sizeof (double) ? 0.0000001 : 0.0001F) || exp10f(5.0F) < ( 10.0F)*( 10.0F)*( 10.0F)*( 10.0F)*( 10.0F) -0.0001F || exp10f(5.0F) > ( 10.0F)*( 10.0F)*( 10.0F)*( 10.0F)*( 10.0F) +0.0001F || exp10l(5.0L) < ( 10.0L)*( 10.0L)*( 10.0L)*( 10.0L)*( 10.0L) -(sizeof (float) < sizeof (long double) ? 0.0000000000001L : 0.0001F) || exp10l(5.0L) > ( 10.0L)*( 10.0L)*( 10.0L)*( 10.0L)*( 10.0L) +(sizeof (float) < sizeof (long double) ? 0.0000000000001L : 0.0001F)) link_failure_exp10_INT();
  extern void link_failure_pow10_INT(void); if (pow10(5.0) < (10.0)*(10.0)*(10.0)*(10.0)*(10.0) - (sizeof (float) < sizeof (double) ? 0.0000001 : 0.0001F) || pow10(5.0) > (10.0)*(10.0)*(10.0)*(10.0)*(10.0) + (sizeof (float) < sizeof (double) ? 0.0000001 : 0.0001F) || pow10f(5.0F) < ( 10.0F)*( 10.0F)*( 10.0F)*( 10.0F)*( 10.0F) -0.0001F || pow10f(5.0F) > ( 10.0F)*( 10.0F)*( 10.0F)*( 10.0F)*( 10.0F) +0.0001F || pow10l(5.0L) < ( 10.0L)*( 10.0L)*( 10.0L)*( 10.0L)*( 10.0L) -(sizeof (float) < sizeof (long double) ? 0.0000000000001L : 0.0001F) || pow10l(5.0L) > ( 10.0L)*( 10.0L)*( 10.0L)*( 10.0L)*( 10.0L) +(sizeof (float) < sizeof (long double) ? 0.0000000000001L : 0.0001F)) link_failure_pow10_INT();







  extern void link_failure_exp_log_same(void); if (exp(log(d1)) != d1 || expf( logf(f1)) != f1 || expl( logl(ld1)) != ld1) link_failure_exp_log_same();
  extern void link_failure_exp2_log2_same(void); if (exp2(log2(d1)) != d1 || exp2f( log2f(f1)) != f1 || exp2l( log2l(ld1)) != ld1) link_failure_exp2_log2_same();
  extern void link_failure_exp10_log10_same(void); if (exp10(log10(d1)) != d1 || exp10f( log10f(f1)) != f1 || exp10l( log10l(ld1)) != ld1) link_failure_exp10_log10_same();
  extern void link_failure_pow10_log10_same(void); if (pow10(log10(d1)) != d1 || pow10f( log10f(f1)) != f1 || pow10l( log10l(ld1)) != ld1) link_failure_pow10_log10_same();







  extern void link_failure_expXexp(void); if (exp(d1)*exp(d2) != exp(d1+d2) || expf(f1)*expf(f2) != expf(f1+f2) || expl(ld1)*expl(ld2) != expl(ld1+ld2)) link_failure_expXexp();
  extern void link_failure_exp2Xexp2(void); if (exp2(d1)*exp2(d2) != exp2(d1+d2) || exp2f(f1)*exp2f(f2) != exp2f(f1+f2) || exp2l(ld1)*exp2l(ld2) != exp2l(ld1+ld2)) link_failure_exp2Xexp2();
  extern void link_failure_exp10Xexp10(void); if (exp10(d1)*exp10(d2) != exp10(d1+d2) || exp10f(f1)*exp10f(f2) != exp10f(f1+f2) || exp10l(ld1)*exp10l(ld2) != exp10l(ld1+ld2)) link_failure_exp10Xexp10();
  extern void link_failure_pow10Xpow10(void); if (pow10(d1)*pow10(d2) != pow10(d1+d2) || pow10f(f1)*pow10f(f2) != pow10f(f1+f2) || pow10l(ld1)*pow10l(ld2) != pow10l(ld1+ld2)) link_failure_pow10Xpow10();
  extern void link_failure_div1_exp(void); if (d1/exp(d2) != d1*exp(-d2) || f1/expf(f2) != f1*expf(-f2) || ld1/expl(ld2) != ld1*expl(-ld2)) link_failure_div1_exp(); extern void link_failure_div2_exp(void); if (exp(d1)/exp(d2) != exp(d1-d2) || expf(f1)/expf(f2) != expf(f1-f2) || expl(ld1)/expl(ld2) != expl(ld1-ld2)) link_failure_div2_exp();
  extern void link_failure_div1_exp2(void); if (d1/exp2(d2) != d1*exp2(-d2) || f1/exp2f(f2) != f1*exp2f(-f2) || ld1/exp2l(ld2) != ld1*exp2l(-ld2)) link_failure_div1_exp2(); extern void link_failure_div2_exp2(void); if (exp2(d1)/exp2(d2) != exp2(d1-d2) || exp2f(f1)/exp2f(f2) != exp2f(f1-f2) || exp2l(ld1)/exp2l(ld2) != exp2l(ld1-ld2)) link_failure_div2_exp2();
  extern void link_failure_div1_exp10(void); if (d1/exp10(d2) != d1*exp10(-d2) || f1/exp10f(f2) != f1*exp10f(-f2) || ld1/exp10l(ld2) != ld1*exp10l(-ld2)) link_failure_div1_exp10(); extern void link_failure_div2_exp10(void); if (exp10(d1)/exp10(d2) != exp10(d1-d2) || exp10f(f1)/exp10f(f2) != exp10f(f1-f2) || exp10l(ld1)/exp10l(ld2) != exp10l(ld1-ld2)) link_failure_div2_exp10();
  extern void link_failure_div1_pow10(void); if (d1/pow10(d2) != d1*pow10(-d2) || f1/pow10f(f2) != f1*pow10f(-f2) || ld1/pow10l(ld2) != ld1*pow10l(-ld2)) link_failure_div1_pow10(); extern void link_failure_div2_pow10(void); if (pow10(d1)/pow10(d2) != pow10(d1-d2) || pow10f(f1)/pow10f(f2) != pow10f(f1-f2) || pow10l(ld1)/pow10l(ld2) != pow10l(ld1-ld2)) link_failure_div2_pow10();
}

int main (void)
{
  return 0;
}
