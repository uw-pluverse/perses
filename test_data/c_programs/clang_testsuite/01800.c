void test_stdbool_initialization(int y) {
  bool constant = 2;
  if (y < 0) {
    bool x = y;
    return;
  }
  if (y > 1) {
    bool x = y;
    return;
  }
  bool x = y;
}
void test_stdbool_assignment(int y) {
  bool x = 0;
  if (y < 0) {
    x = y;
    return;
  }
  if (y > 1) {
    x = y;
    return;
  }
  x = y;
}
typedef signed char BOOL;
void test_BOOL_initialization(int y) {
  BOOL constant = 2;
  if (y < 0) {
    BOOL x = y;
    return;
  }
  if (y > 200 && y < 250) {
    BOOL x = y;
    return;
  }
  if (y >= 127 && y < 150) {
    BOOL x = y;
    return;
  }
  if (y > 1) {
    BOOL x = y;
    return;
  }
  BOOL x = y;
}
void test_BOOL_assignment(int y) {
  BOOL x = 0;
  if (y < 0) {
    x = y;
    return;
  }
  if (y > 1) {
    x = y;
    return;
  }
  x = y;
}
typedef unsigned char Boolean;
void test_Boolean_initialization(int y) {
  Boolean constant = 2;
  if (y < 0) {
    Boolean x = y;
    return;
  }
  if (y > 1) {
    Boolean x = y;
    return;
  }
  Boolean x = y;
}
void test_Boolean_assignment(int y) {
  Boolean x = 0;
  if (y < 0) {
    x = y;
    return;
  }
  if (y > 1) {
    x = y;
    return;
  }
  x = y;
}
