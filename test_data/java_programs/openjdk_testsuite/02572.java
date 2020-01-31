
class MissingAnnotationValue {
  void test() {
    String[] a = new String @A [5];
  }
}

@interface A { int field(); }
