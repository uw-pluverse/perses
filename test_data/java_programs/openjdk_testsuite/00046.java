



public class Covar2 {
    static class A1 {
        public Long f() { return 12L; }
    }
    static class B1 extends A1 {
        public Long f() { return 12L; }
    }

    static class B2 {
        public int f() { return 12; }
    }
    static class C2 extends B2 {
        public int f() { return (short)12; }
    }

    static class C3 extends B2 {
        public int f() { return (short)12; }
    }

    public static void main(String[] args) {
        A1 b1 = new B1();
        System.out.println(b1.f());

        B2 c2 = new C2();
        System.out.println(c2.f());

        B2 c3 = new C3();
        System.out.println(c3.f());
    }
}
