



import a.Pub;
import java.lang.reflect.*;

public class T6342411 {
    public static void main(String[] args) throws Exception {
        Pub p = new Pub();
        p.f();
        Method m = Pub.class.getMethod("f");
        m.invoke(p);
    }
}
