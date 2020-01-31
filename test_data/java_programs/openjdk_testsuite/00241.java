



public class T6569404c {
    static class Outer {
      class Inner {}
    }

    static class Test<X extends Outer>  {
       class InnerTest extends X.Inner { InnerTest(Outer o) {o.super();} }
    }

    public static void main(String[] args) {
       new Test<Outer>().new InnerTest(new Outer());
    }
}
