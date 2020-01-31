



public class MethodRef2 {

    static interface A {String m();}

    static interface B {String m(int i);}

    private static void assertTrue(boolean cond) {
        if (!cond)
            throw new AssertionError();
    }

    String moo() {
        return "moo";
    }

    String wahoo() {
        return "wahoo";
    }

    String wahoo(int x) {
        return "wahoo " + x;
    }

    public static void main(String[] args) {

        MethodRef2 mr = new MethodRef2();

        A a = mr::moo; 
        assertTrue( a.m().equals("moo") );

        a = new MethodRef2()::wahoo; 
        assertTrue( a.m().equals("wahoo") );

        B b = mr::wahoo; 
        assertTrue( b.m(4).equals("wahoo 4") );
    }
}
