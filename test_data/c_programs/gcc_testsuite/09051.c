



extern __thread int __libc_errno __attribute__ ((tls_model ("initial-exec")));
;
int *
__errno_location (void)
{
  return &__libc_errno;
}
