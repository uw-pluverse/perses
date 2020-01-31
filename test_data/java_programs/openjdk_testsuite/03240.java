



public class LambdaTest5 {

    interface A {
        int m();
    }

    interface B {
        int make (int i);
    }

    private static int count = 0;

    private static void assertTrue(boolean b) {
        if(!b)
            throw new AssertionError();
    }

    static A a;
    static A a2;
    static A a3;
    static A a4;

    public static void main(String[] args) {
        B b = (int i) -> ((A)()-> 5).m();
        assertTrue(b.make(0) == 5);

        a = () -> ((A)()-> { return 6; }).m(); 
        assertTrue(a.m() == 6);

        a2 = ()-> {
                  A an = ()-> { return 7; }; 
                  return an.m();
                };
        assertTrue(a2.m() == 7);

        a3 = () -> a3.m(); 
        try {
            a3.m();
        } catch(StackOverflowError e) {
            count++;
        }
        assertTrue(count==1);

        a4 = ()-> ((B)(int i)-> ((A)()-> 9).m() ).make(0);
        assertTrue(a4.m() == 9);
    }
}
