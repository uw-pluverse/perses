



public class T5073060a {
    static class C1 {
        void c1m1() {
            System.out.println("FISK");
        }
    }
    static interface I {}

    static class C2 extends C1 implements I {}

    static class C3 extends C1 implements I {}

    public <T> T m1(T t1, T t2) { return t1; }

    public <T extends C1 & I> void test(C2 c2, C3 c3, T t) {
        m1(c2, c3).c1m1(); 
        t.c1m1(); 
        (t != null ? c2 : c3).c1m1(); 
    }

    public static void main(String... args) {
        T5073060a t = new T5073060a();
        t.test(new C2(), new C3(), new C2());
    }
}
