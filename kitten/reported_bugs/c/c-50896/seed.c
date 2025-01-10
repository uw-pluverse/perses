



void test_memcpy_inline_0(void *dst, const void *src) {

  __builtin_memcpy_inline(dst, src, 0);
}


void test_memcpy_inline_1(void *dst, const void *src) {

  __builtin_memcpy_inline(dst, src, 1);
}


void test_memcpy_inline_4(void *dst, const void *src) {

  __builtin_memcpy_inline(dst, src, 4);
}


void test_memcpy_inline_aligned_buffers(unsigned long long *dst, const unsigned long long *src) {

  __builtin_memcpy_inline(dst, src, 4);
}
