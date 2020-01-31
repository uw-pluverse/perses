

class Foo {
   Foo(String v) {}
};

class Test {
   public static void main() {
      Foo f = new Foo("Hello!",nosuchfunction()) {};
   }
}
