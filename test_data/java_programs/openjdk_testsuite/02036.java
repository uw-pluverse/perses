



import static a.Named.x;
import static a.Named.X;
import static a.Star.*;

public class T6225935 {
    public static void main(String[] args) {
        X o1 = new X();
        Y o2 = new Y();
        x();
        System.err.println(x);
        y();
        System.err.println(y);
    }
}
