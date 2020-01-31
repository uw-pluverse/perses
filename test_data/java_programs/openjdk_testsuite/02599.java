
import java.util.HashMap;
import java.util.Map;

class T6227617 {
    void m() {
        int i1 = 2;
        int i2 = (int) i1;  

        float f1 = 1f;
        int i3 = (int) f1;

        String s = (String) ""; 
        Object o = (Object) "";

        Map<String, Integer> m = new HashMap<String, Integer>();
        Integer I1 = (Integer) m.get(""); 
    }

    
    static final int i1 = Foo.i1;
    static final String s = Foo.s;
}

class Foo
{
    static final int i1 = (int) 1;
    static final int i2 = (int) 1L;

    static final String s = (String) "abc";
}
