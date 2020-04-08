int main() {
  (void)'é';
  (void)u'é';
  (void)U'é';
  (void)L'é';
  static_assert((unsigned char)'é' == 0xE9, "");
  static_assert('éé' == 0xE9E9, "");
}
