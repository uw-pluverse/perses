





import java.util.*;

public class T654170 {
    public static void main(String[] args) {
        Base<?> b = new Sub ();
        if (b instanceof Sub) {
        }
    }
}

class Base<T extends List> {}

class Sub extends Base<ArrayList> {}
