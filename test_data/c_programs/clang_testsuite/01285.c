int __isOSVersionAtLeast(int Major, int Minor, int Subminor);
int main() {
  if (__isOSVersionAtLeast(1, 0, 0))
    return 1;
  return 0;
}
