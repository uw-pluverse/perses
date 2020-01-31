extern void external_callme(void (*callback)(void));
extern void external_longjmp(char *msg);
extern void external_check_stack(void);
static void callback(void) {
  char msg[16];
  external_longjmp(msg);
}
int main() {
  external_callme(callback);
  external_check_stack();
  return 0;
}
