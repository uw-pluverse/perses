



public class DeadCode3
{
    private final void fun1() { }

    private void fun2() {
        DeadCode3 r1 = null;
        fun1();

        
        r1.fun1();
    }

    public static void main( String[] args ) {
        try {
            new DeadCode3() . fun2();
            
            throw new RuntimeException("accidental removal of live code");
        } catch (NullPointerException e) {
            System.out.println("NullPointerException correctly thrown");
            e.printStackTrace();
        }
    }
}
