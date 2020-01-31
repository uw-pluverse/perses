void *malloc(long unsigned int size) __attribute__ ((__nothrow__));
inline static void __zend_malloc() {
    malloc(1);
}
void *malloc(long unsigned int size) __attribute__ ((__nothrow__));
void fontFetch() {
    __zend_malloc(1);
}
