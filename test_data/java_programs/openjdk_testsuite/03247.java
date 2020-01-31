



public class SamConversion {

    static interface Foo {
        Integer m(int i);
    }

    static interface Bar {
        int m(Integer i) throws Exception;
    }

    private static String assertionStr = "";

    private static void assertTrue(boolean b) {
        if(!b)
            throw new AssertionError();
    }

    private static void test1(Foo foo) {
        assertTrue(foo.m(1) == 2);
    }

    private static void test2(Bar bar) {
        try {
            assertTrue(bar.m(1) == 2);
        } catch (Exception e){
            assertTrue(false);
        }
    }

    private static Bar test3(int i) {
        switch (i) {
        case 0:
            return n -> n + 1;
        case 1:
            return (Integer n) -> 2 * n;
        case 2:
            return (Integer n) -> {return new Integer(n-1);};
        case 3:
            return n -> {throw new Exception();};
        default:
            return null;
        }
    }

    public static void main(String[] args) {

        
        Foo foo = (int n) -> n + 1; 
        assertTrue(foo.m(1) == 2);

        foo = n -> n + 1; 
        assertTrue(foo.m(1) == 2);

        Bar bar = (Integer n) -> n + 1; 
        try {
            assertTrue(bar.m(1) == 2);
        } catch (Exception e) {
            assertTrue(false);
        }

        bar = (Integer n) -> new Integer(n+1); 
        try {
            assertTrue(bar.m(1) == 2);
        } catch (Exception e) {
            assertTrue(false);
        }

        bar = n -> n.intValue() + 1; 
        try {
            assertTrue(bar.m(1) == 2);
        } catch (Exception e) {
            assertTrue(false);
        }

        bar = n -> n + 1; 
        try {
            assertTrue(bar.m(1) == 2);
        } catch (Exception e) {
            assertTrue(false);
        }

        
        assertTrue(((Foo)n -> {return n+1;}).m(1) == 2); 
        try {
            assertTrue(((Bar)n -> {return n+1;}).m(1) == 2); 
        } catch (Exception e) {
            assertTrue(false);
        }

        
        test1((int n) -> new Integer(n+1)); 
        test2((Integer n) -> n.intValue() + 1); 

        
        bar = test3(0);
        try {
            assertTrue(bar.m(1) == 2);
        } catch (Exception e) {
            assertTrue(false);
        }
        bar = test3(1);
        try {
            assertTrue(bar.m(3) == 6);
        } catch (Exception e) {
            assertTrue(false);
        }
        bar = test3(2);
        try {
            assertTrue(bar.m(10) == 9);
        } catch (Exception e) {
            assertTrue(false);
        }
        bar = test3(3);
        try {
            bar.m(10);
            assertTrue(false);
        } catch (Exception e) {}
    }
}
