void do_nothing();
void assert_error();
void test1() {
  if (0 && "foo") do_nothing(); else assert_error();
  if ("foo" && 0) do_nothing(); else assert_error();
  if (0 || "foo") do_nothing(); else assert_error();
  if ("foo") do_nothing(); else assert_error();
  ((0 && "foo") ? do_nothing() : assert_error());
  (("foo" && 0) ? do_nothing() : assert_error());
  ((0 || "foo") ? do_nothing() : assert_error());
  (("foo") ? do_nothing() : assert_error());
}
void test2() {
  if ("hi") {}
  while ("hello") {}
  for (;"howdy";) {}
  do { } while ("hey");
  int x = "hey" ? 1 : 2;
}
