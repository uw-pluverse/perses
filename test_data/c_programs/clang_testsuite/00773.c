int main() {
  char b[10] = "\u1120\u0220\U00102030";
  const wchar_t *foo = L"AB";
  const wchar_t *bar = L"\u1120\u0220\U00102030";
  char c = 'ab';
  wchar_t wa = L'a';
  wchar_t wb = L'ab';
  wchar_t wc = L'\uF00B';
}
