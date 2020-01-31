

class InvalidLocation {
  void test() {
    new @A String();
  }
}

@java.lang.annotation.Target(java.lang.annotation.ElementType.TYPE)
@interface A { }
