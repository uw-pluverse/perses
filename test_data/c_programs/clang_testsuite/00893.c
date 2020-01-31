int i;
void dead();
void test1() {
  switch (1)
    case 1:
      ++i;
  switch (0)
    case 1:
      dead();
}
void test2() {
  switch (4) {
  case 1:
    dead();
    break;
  case 4:
    i += 2;
  }
}
void test3() {
  switch (4) {
  case 1:
    dead();
    break;
  case 4: {
    i += 2;
    break;
  }
  }
}
void test4() {
  switch (4) {
    case 1:
      dead();
      break;
    default: {
      i += 2;
      break;
    }
  }
}
void test5() {
  switch (1) {
    int x;
    case 1:
      x = 4;
      i = x;
      break;
  }
}
void test6() {
  switch (40) {
  case 1:
   dead();
    break;
  case 4: {
    dead();
    break;
  }
  }
}
void test7() {
  switch (4) {
  case 1:
      dead();
    break;
    {
      case 4:
        ++i;
    }
    break;
  }
}
void test8() {
  switch (4) {
  case 1:
    dead();
    break;
  case 4:
    ++i;
  }
}
void test9(int i) {
  switch (1) {
  case 5:
    dead();
  case 1:
    ++i;
  case 4:
    ++i;
    break;
  }
}
int test10(void) {
 switch(8) {
  case 8:
   break;
  case 4:
   break;
  default:
   dead();
 }
 return 0;
}
void test11() {
  switch (1) {
    case 1:
      break;
    case 42: ;
      int x;
      x = 4;
      break;
  }
}
void test12() {
  switch (1) {
  case 2: {
     int a;
     a = 42;
   }
  case 1:
    break;
  case 42: ;
    int x;
    x = 4;
    break;
  }
}
void test13(int x) {
  switch (x) {
    case 42: test13(97);
    case 11: break;
    default: test13(42); break;
  }
}
