



public class T6569404a {

    static class Outer {
      public class Inner {}
    }

    static class Test<T extends Outer> {
       public Test(T t) {
          Outer.Inner inner = t.new Inner();
       }
    }

    public static void main(String[] args) {
       new Test<Outer>(new Outer());
    }
}
