void* a(unsigned x) {
return __builtin_return_address(0);
}
void b(unsigned x) {
return __builtin_return_address(x);
}
void* c(unsigned x) {
return __builtin_frame_address(0);
}
void d(unsigned x) {
return __builtin_frame_address(x);
}
