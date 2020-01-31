

class MethodReference08 {
    interface SAM {
       String m(Foo f);
    }

    static class Foo<X> {
       String getX() { return null; }

       static void test() {
          SAM s = Foo::getX;
       }
    }
}
