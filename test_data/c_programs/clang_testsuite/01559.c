enum Choices {
  CHOICE_0 = 0,
  CHOICE_1 = 1
};
enum Unchoices {
  UNCHOICE_0 = 0,
  UNCHOICE_1 = 1
};
void f(int x) {
  int y = 0;
  if (x > 2 || x < 1) { }
  if (x > 2 || x < 2) { }
  if (x != 2 || x != 3) { }
  if (x > 2 || x < 3) { }
  if (x > 0 || x < 0) { }
  if (x > 2 || x <= 1) { }
  if (x > 2 || x <= 2) { }
  if (x > 2 || x <= 3) { }
  if (x >= 2 || x < 1) { }
  if (x >= 2 || x < 2) { }
  if (x >= 2 || x < 3) { }
  if (x >= 2 || x <= 1) { }
  if (x >= 2 || x <= 2) { }
  if (x >= 2 || x <= 3) { }
  if (x >= 0 || x <= 0) { }
  if (x > 2 && x < 1) { }
  if (x > 2 && x < 2) { }
  if (x > 2 && x < 3) { }
  if (x > 0 && x < 1) { }
  if (x > 2 && x <= 1) { }
  if (x > 2 && x <= 2) { }
  if (x > 2 && x <= 3) { }
  if (x >= 2 && x < 1) { }
  if (x >= 2 && x < 2) { }
  if (x >= 2 && x < 3) { }
  if (x >= 0 && x < 0) { }
  if (x >= 2 && x <= 1) { }
  if (x >= 2 && x <= 2) { }
  if (x >= 2 && x <= 3) { }
  if (x != 2 || x != 3) { }
  if (x != 2 || x < 3) { }
  if (x == 2 && x == 3) { }
  if (x == 2 && x > 3) { }
  if (x == 3 && x < 0) { }
  if (3 == x && x < 0) { }
  if (x == 2 && x > 3) { }
  if (x == (2 + 1) && x > 3) { }
  if (x != CHOICE_0 || x != CHOICE_1) { }
  if (x == CHOICE_0 && x == CHOICE_1) { }
  if (x == CHOICE_0 && x == 1) { }
  if (x != CHOICE_0 || x != 1) { }
  if (x == CHOICE_0 && x == UNCHOICE_1) { }
  if (x != CHOICE_0 || x != UNCHOICE_1) { }
}
void enums(enum Choices c) {
  if (c != CHOICE_0 || c != CHOICE_1) { }
  if (c == CHOICE_0 && c == CHOICE_1) { }
  if (c == CHOICE_0 && c == 1) { }
  if (c != CHOICE_0 || c != 1) { }
  if (c == CHOICE_0 && c == UNCHOICE_1) { }
  if (c != CHOICE_0 || c != UNCHOICE_1) { }
}
void array_out_of_bounds() {
  int x;
  int buffer[4];
  x = (-7 > 0) ? (buffer[-7]) : 0;
}
void bool_contexts(int x) {
  if (x > 4 || x < 10) {}
  for (;x > 4 || x < 10;) {}
  while (x > 4 || x < 10) {}
  do {} while (x > 4 || x < 10);
  x = (x > 4 || x < 10) ? 1 : 2;
  if ((void)5, x > 4 || x < 10) {}
}
void assignment(int x) {
  int a = x > 4 || x < 10;
  int b = x < 2 && x > 5;
  int c = x != 1 || x != 3;
  int d = x == 1 && x == 2;
  int e = x < 1 || x != 0;
}
int returns(int x) {
  return x > 4 || x < 10;
  return x < 2 && x > 5;
  return x != 1 || x != 3;
  return x == 1 && x == 2;
  return x < 1 || x != 0;
}
