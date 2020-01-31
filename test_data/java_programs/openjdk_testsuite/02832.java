





class A {
  int i = 12;
  abstract class B {
    { foo(); }
    abstract void foo();
  }
}
public class Closure5 extends A {
  int i;
  public static void main(String[] args) {
    new Closure5().new D();
  }
  class D extends B {
    int i;
    void foo() {
      if (Closure5.super.i != 12) throw new Error("4416605");
    }
  }
}
