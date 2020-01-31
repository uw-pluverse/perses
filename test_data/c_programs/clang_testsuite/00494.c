char buffer[32] = "This is a largely unused buffer";
int main() {
  __builtin___clear_cache(buffer, buffer+32);
  return 0;
}
