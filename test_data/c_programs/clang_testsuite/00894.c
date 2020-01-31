extern void OldFunction() __attribute__((deprecated));
int main (int argc, const char * argv[]) {
  OldFunction();
}
