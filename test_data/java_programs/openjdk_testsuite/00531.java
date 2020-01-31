



import java.util.*;

class G3 {

    G3(Enumeration<Object> e) { }

    static void g() {
        new G3(new Enumeration() {
                public boolean hasMoreElements() { return false; }
                public Object nextElement() { return null; }
            });
    }

}
