



public class SamConversion {

    static int assertionCount = 0;

    static interface Foo {
        Integer m(int i);
    }

    static interface Bar {
        int m(Integer i) throws MyException;
    }

    private static void assertTrue(boolean b) {
        assertionCount++;
        if(!b)
            throw new AssertionError();
    }

    private static int test1(Foo foo) {
        return foo.m(1);
    }

    private static void test2(Bar bar, int result) {
        try {
            assertTrue(bar.m(1) == result);
        } catch (Exception e){
            assertTrue(false);
        }
    }

    private static Bar test3(int i) {
        switch (i) {
        case 0:
            return A::method1;
        case 1:
            return new A()::method2;
        case 2:
            return A::method3;
        case 3:
            return new A()::method4;
        case 4:
            return new A()::method5;
        case 5:
            return A::method6;
        default:
            return null;
        }
    }

    
    private static void testAssignment() {
        Foo foo = A::method1; 
        assertTrue(foo.m(1) == 2);

        foo = new A()::method2; 
        assertTrue(foo.m(1) == 3);

        foo = A::method3; 
        assertTrue(foo.m(1) == 4);

        foo = new A()::method4; 
        assertTrue(foo.m(1) == 5);

        foo = new A()::method5; 
        assertTrue(foo.m(1) == 6);

        Bar bar = A::method1;
        try {
            assertTrue(bar.m(1) == 2);
        } catch (Exception e) {
            assertTrue(false);
        }

        bar = new A()::method2;
        try {
            assertTrue(bar.m(1) == 3);
        } catch (Exception e) {
            assertTrue(false);
        }

        bar = A::method3;
        try {
            assertTrue(bar.m(1) == 4);
        } catch (Exception e) {
            assertTrue(false);
        }

        bar = new A()::method4;
        try {
            assertTrue(bar.m(1) == 5);
        } catch (Exception e) {
            assertTrue(false);
        }

        bar = new A()::method5;
        try {
            assertTrue(bar.m(1) == 6);
        } catch (Exception e) {
            assertTrue(false);
        }
    }

    
    private static void testMethodArgument() {
        assertTrue(test1(A::method1) == 2);
        assertTrue(test1(new A()::method2) == 3);
        assertTrue(test1(A::method3) == 4);
        assertTrue(test1(new A()::method4) == 5);
        assertTrue(test1(new A()::method5) == 6);
        test2(A::method1, 2);
        test2(new A()::method2, 3);
        test2(A::method3, 4);
        test2(new A()::method4, 5);
        test2(new A()::method5, 6);
    }

    
    private static void testReturnStatement() {
        Bar bar = test3(0);
        try {
            assertTrue(bar.m(1) == 2);
        } catch (Exception e) {
            assertTrue(false);
        }
        bar = test3(1);
        try {
            assertTrue(bar.m(1) == 3);
        } catch (Exception e) {
            assertTrue(false);
        }
        bar = test3(2);
        try {
            assertTrue(bar.m(1) == 4);
        } catch (Exception e) {
            assertTrue(false);
        }
        bar = test3(3);
        try {
            assertTrue(bar.m(1) == 5);
        } catch (Exception e) {
            assertTrue(false);
        }
        bar = test3(4);
        try {
            assertTrue(bar.m(1) == 6);
        } catch (Exception e) {
            assertTrue(false);
        }
        bar = test3(5);
        try {
            bar.m(1);
            assertTrue(false);
        } catch (MyException e) {
        } catch (Exception e) {
            assertTrue(false);
        }
    }

    
    private static void testCast() {
        assertTrue(((Foo)A::method1).m(1) == 2);
        try {
            assertTrue(((Bar)new A()::method2).m(1) == 3);
        } catch (Exception e) {
            assertTrue(false);
        }
    }

    
    private static void testArrayInitializer() {
        Object[] oarray = {"a", 1, (Foo)A::method3}; 
        Object[] oarray2 = {"a", 1, (Bar)new A()::method4}; 
        Foo[] farray = {A::method1, new A()::method2, A::method3, new A()::method4, new A()::method5};
        Bar[] barray = {A::method1, new A()::method2, A::method3, new A()::method4, new A()::method5, A::method6};
    }

    
    private static void testConditionalExpression(boolean b) {
        Foo f = b ? A::method3 : new A()::method5;
        if(b)
            assertTrue(f.m(1) == 4);
        else
            assertTrue(f.m(1) == 6);

        Bar bar = b ? A::method1 : A::method6;
        if(b) {
            try {
                assertTrue(bar.m(1) == 2);
            } catch (Exception e) {
                assertTrue(false);
            }
        }
        else {
            try {
                bar.m(1);
                assertTrue(false);
            } catch (MyException e) {
            } catch (Exception e) {
                assertTrue(false);
            }
        }
    }

    
    private static void testLambdaExpressionBody() {
        Foo f = n -> ((Foo)A::method3).m(n);
        assertTrue(f.m(1) == 4);

        Bar b = n -> { return ((Foo)new A()::method5).m(n); };
        try {
            assertTrue(b.m(1) == 6);
        } catch (Exception e) {
            assertTrue(false);
        }
    }

    public static void main(String[] args) {
        testAssignment();
        testMethodArgument();
        testReturnStatement();
        testCast();
        testArrayInitializer();
        testConditionalExpression(true);
        testConditionalExpression(false);
        testLambdaExpressionBody();

        assertTrue(assertionCount == 32);
    }

    static class MyException extends Exception {}

    static class A {

        int value = 0;

        A() {
        }

        A(Foo f) {
            value = f.m(9);
        }

        A(Bar b) {
            try {
                value = b.m(9);
            } catch (MyException e){}
        }

        static Integer method1(int n) {
            return n + 1;
        }

        int method2(Integer n) {
            return value == 0 ? n + 2 : n + value;
        }

        static int method3(int n) {
            return n + 3;
        }

        Integer method4(Integer n) {
            return value == 0 ? n + 4 : n + value;
        }

        Integer method5(Integer n) {
            return value == 0 ? new Integer(n + 5) : new Integer(n + value);
        }

        static int method6(Integer n) throws MyException{
            throw new MyException();
        }
    }
}
