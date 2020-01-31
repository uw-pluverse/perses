const char* test1 = 1 ? "i" : 1 == 1 ? "v" : "r";
void _efree(void *ptr);
void free(void *ptr);
int _php_stream_free1() {
  return (1 ? free(0) : _efree(0));
}
int _php_stream_free2() {
  return (1 ? _efree(0) : free(0));
}
