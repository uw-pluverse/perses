
class MissingAnnotationValue {
  void test() {
    String @A [] s;
  }
}

@interface A { int field(); }
