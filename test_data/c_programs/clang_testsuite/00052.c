int main() {
  (void)'י';
  (void)u'י';
  (void)U'י';
  (void)L'י';
  static_assert((unsigned char)'י' == 0xE9, "");
  static_assert('יי' == 0xE9E9, "");
}
