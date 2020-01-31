
class InvalidLocation {
  void innermethod() {
    class Inner<@A K> {}
  }
}

@java.lang.annotation.Target(java.lang.annotation.ElementType.TYPE)
@interface A { }
