__attribute__((availability(macos, introduced=10.12)))
int function(void);
void use() {
  function();
}
