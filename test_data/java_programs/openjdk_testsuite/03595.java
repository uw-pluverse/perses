



import java.util.Vector; 

public class AnonInnerClass extends Vector {

    public static void main(String[] args) {
        new AnonInnerClass().test();
    }

    public void test() {
        Runnable r = new Runnable() {
            public void run() {
                
                AnonInnerClass.this.removeRange(0,0);
            }
        };
    }
}
