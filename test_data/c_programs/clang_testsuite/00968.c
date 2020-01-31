void PR13497() {
  char content[2];
  __builtin___strcpy_chk(content, "", 1);
}
void PR4941(char *s) {
  for (unsigned i = 0; i < 8192; ++i)
    s[i] = 0;
}
