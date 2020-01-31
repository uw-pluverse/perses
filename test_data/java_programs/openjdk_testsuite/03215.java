





public class MethodReferenceIntersection3 {
  interface A {}

  interface Foo {
    <T extends Object & A> void foo(T t);
  }

  static <T extends A> void bar(T t) {
  }

  public static void main(String[] args) {
    Foo foo = MethodReferenceIntersection3::bar;
    foo.foo(new A(){});
  }
}
