void f() {
  (void)_mm_getcsr();
  _mm_setcsr(1);
  _mm_sfence();
  _mm_clflush((void*)0);
  _mm_lfence();
  _mm_mfence();
  _mm_pause();
}
unsigned int _mm_getcsr();
void _mm_setcsr(unsigned int);
void _mm_sfence();
void _mm_clflush(void const *);
void _mm_lfence();
void _mm_mfence();
void _mm_pause();
void g() {
  (void)_mm_getcsr();
  _mm_setcsr(1);
  _mm_sfence();
  _mm_clflush((void*)0);
  _mm_lfence();
  _mm_mfence();
  _mm_pause();
}
