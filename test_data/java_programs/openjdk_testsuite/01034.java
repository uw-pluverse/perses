



class cls
{
    static int arr[];

    static {
        arr = new int[2];
        arr[0] = 0;
        arr[1] = 2;
    }
}

public class DeadCode4
{
    final int x = 9;

    private final void fun1() {
        try {
            int i = cls.arr[3];
            
            throw new RuntimeException("accidental removal of live code");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException correctly thrown");
            e.printStackTrace();
        }
    }

    public static void main( String[] args )
    {
        DeadCode4 r1 = new DeadCode4();
        r1.fun1();
    }
}
