
class MissingAnnotationValue {
  void innermethod() {
    class Inner<@A K> { }
  }
}

@interface A { int field(); }
