



public class MethodReference12 {

    interface SAM { void foo(int i); }

    static void print(int i) {
        System.out.println(i);
    }

    public static void main(String[] args) {
        try {
            test(MethodReference12::print);
            test(i -> { System.out.println(i); } );
        }
        catch (Throwable t) {
            t.printStackTrace();
            throw new AssertionError("An error occurred");
        }
    }

    static void test(SAM s) throws Throwable {
        s.hashCode();
        s.equals(null);
        s.toString();
        try {
            s.notify(); 
        }
        catch (final IllegalMonitorStateException e) {  }
        try {
            s.notifyAll(); 
        }
        catch (final IllegalMonitorStateException e) {  }
        try {
            s.wait(1); 
        }
        catch (final IllegalMonitorStateException | InterruptedException e) {  }
        try {
            s.wait(1,1); 
        }
        catch (final IllegalMonitorStateException | InterruptedException e) {  }
        try {
            s.wait(); 
        }
        catch (final IllegalMonitorStateException | InterruptedException e) {  }
    }
}
