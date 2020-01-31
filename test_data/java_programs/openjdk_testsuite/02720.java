






import java.util.ArrayList;

public class ImplicitToString {
    public static void main(String[] args) {
        String s = "";
        ArrayList al = new ArrayList();
        al.add(new Object());

        
        s += al.get(0);
    }
}
