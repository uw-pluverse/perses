



public class AmbiguityErrorTest {

    public interface A { }

    public interface B extends A { }

    public interface C {
        A m(B strategy);
    }

    public interface D {
        A m(A strategy);
        A m(B strategy);
    }

    public interface T1 extends C, D { }
    public interface T2 extends D, C { }

    int count;

    class T1Impl implements T1, T2 {
        public A m(B strategy) {
            count++;
            return null;
        }
        public A m(A strategy) {
            throw new AssertionError("Should not get here.");
        }
    }

    public static void main(String... args) {
        new AmbiguityErrorTest().test();
    }

    void test() {
        T1 t1 = new T1Impl();
        T2 t2 = new T1Impl();
        final B b = new B() { };
        t1.m(b);
        t2.m(b);

        if (count != 2) {
            throw new IllegalStateException("Did not call the methods properly");
        }
    }

}
