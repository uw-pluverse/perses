



public class T6500343a {
    static class Base {}
    static interface I {}
    static class A1 extends Base implements I {}
    static class A2 extends Base implements I {}

    static Object crash(I i, A1 a1, A2 a2, boolean b1, boolean b2) {
        return b1 ? i : b2 ? a2 : a1;
        
    }

    public static void main(String[] args) {
        T6500343a.crash(new A1(), new A1(), new A2(), true, false);
        T6500343a.crash(new A1(), new A1(), new A2(), false, true);
        T6500343a.crash(new A1(), new A1(), new A2(), false, false);
        T6500343a.crash(new A1(), new A1(), new A2(), true, true);
    }
}

