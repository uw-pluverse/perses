



public class LambdaTest2 {

    private static int count = 0;

    private static void assertTrue(boolean b) {
        if(!b)
            throw new AssertionError();
    }

    public static void main(String[] args) {
        LambdaTest2 test = new LambdaTest2();

        test.method2((int n) -> { ; });
        test.method2(n -> { }); 
        test.method2((int n) -> { }); 
        test.method2((int n) -> { return; }); 
        test.method2((int n) -> { count += n; });
        assertTrue(count == 10);

        VoidInt vi = (int i) -> {
                            switch (i) {
                                case 0:
                                    System.out.println("normal");
                                    break;
                                default:
                                    System.out.println("invalid");
                            }
                       };

        test.method3(()-> { count++; });
        test.method3(() -> {});
        assertTrue(count == 11);

        VoidVoid vv = ()-> { while(true)
                            if(false)
                                break;
                            else
                                continue;
                       };

        IntVoid iv1 = () -> 42;
        IntVoid iv2 = () -> { return 43; };
        assertTrue(iv1.ivMethod() == 42);
        assertTrue(iv2.ivMethod() == 43);

        IntInt ii1 = (int n) -> n+1;
        IntInt ii2 = n -> 42;
        IntInt ii3 = n -> { return 43; };
        IntInt ii4 =
            (int n) -> {
                if(n > 0)
                    return n+1;
                else
                    return n-1;
            };
        assertTrue(ii1.iiMethod(1) == 2);
        assertTrue(ii2.iiMethod(1) == 42);
        assertTrue(ii3.iiMethod(1) == 43);
        assertTrue(ii4.iiMethod(-1) == -2);
    }

    void method2(VoidInt a) {
        a.viMethod(10);
    }

    void method3(VoidVoid a) {
        a.vvMethod();
    }

    
    interface VoidInt {
        void viMethod(int n);
    }

    interface VoidVoid {
        void vvMethod();
    }

    interface IntVoid {
        int ivMethod();
    }

    interface IntInt {
        int iiMethod(int n);
    }
}
