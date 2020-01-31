



public class MethodRef3 {

    static interface A { String m(MethodRef3 mr); }

    static interface B { String m(MethodRef3 mr, String s); }

    private static void assertTrue(boolean cond) {
        if (!cond)
            throw new AssertionError();
    }

    String moo() {
        return "moo";
    }

    String wahoo(String s) {
        return "wahoo " + s;
    }

    public static void main(String[] args) {

        MethodRef3 mr = new MethodRef3();
        A a = MethodRef3::moo; 
        assertTrue( a.m(mr).equals("moo") );
        B b = MethodRef3::wahoo; 
        assertTrue( b.m(mr, "hi").equals("wahoo hi") );
    }
}
