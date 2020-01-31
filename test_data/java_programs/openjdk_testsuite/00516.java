



import java.util.*;

public class MissingCast {
    protected Vector<String> v = null;

    public void f() {
        ((String) (v.elementAt(0))).charAt(0);
    }

    public static void main(String[] args) {}
}
