




extern __thread int *__libc_resp;
int
__res_init(void) {
  return *__libc_resp;
}
