void f() {
  (void)_byteswap_ushort(42);
  (void)_byteswap_uint64(42LL);
}
void _byteswap_ulong();
unsigned short _byteswap_ushort(unsigned short);
unsigned long long _byteswap_uint64(unsigned long long);
void g() {
  (void)_byteswap_ushort(42);
  (void)_byteswap_uint64(42LL);
}
void h() {
  (void)__mulh(21, 2);
  (void)__umulh(21, 2);
}
long long __mulh(long long, long long);
unsigned long long __umulh(unsigned long long, unsigned long long);
void i() {
  (void)__mulh(21, 2);
  (void)__umulh(21, 2);
}
