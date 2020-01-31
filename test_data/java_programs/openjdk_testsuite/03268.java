

interface A {
  static String m() {
    return "A";
  }
}

interface B {
  static String m() {
    return "B";
  }
}

interface AB extends A, B {
 static String m() {
   return A.super.m();
 }
}

