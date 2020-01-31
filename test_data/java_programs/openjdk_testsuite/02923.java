



class MethodReference07 {
    interface SAM {
       String m(Foo<String> f);
    }

    static class Foo<X> {
       String getX() { return null; }

       static void test() {
          SAM s = Foo<String>::getX;
       }
    }
}
