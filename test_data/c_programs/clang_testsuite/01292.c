extern int ext_weak_import __attribute__ ((__weak_import__));
int decl_weak_import __attribute__ ((__weak_import__));
int decl_initialized_weak_import __attribute__ ((__weak_import__)) = 13;
extern int ext_f(void) __attribute__ ((__weak_import__));
int def_f(void) __attribute__ ((__weak_import__));
int __attribute__ ((__weak_import__)) decl_f(void) {return 0;};
