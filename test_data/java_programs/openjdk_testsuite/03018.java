

class MethodReference09 {
    interface SAM {
       String m(Foo f);
    }

    static class Foo<X> {
       String getX() { return null; }

       Foo<X> getThis() { return this; }

       static void test() {
          SAM s1 = Foo.getThis()::getX;
          SAM s2 = this::getX;
       }
    }
}
