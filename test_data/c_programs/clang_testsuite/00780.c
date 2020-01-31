typedef int __attribute__((pcs("aapcs"))) (*aapcs_fn)(void);
typedef int __attribute__((pcs("aapcs-vfp"))) (*aapcs_vfp_fn)(void);
aapcs_fn bar;
int foo(aapcs_vfp_fn baz) {
  return bar() + baz();
}
