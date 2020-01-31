

import java.util.List;

class T7097436 {
    @SafeVarargs
    static void m(List<String>... ls) {
        Object o = ls; 
        Object[] oArr = ls; 
        String s = ls; 
        Integer[] iArr = ls; 
    }
}
