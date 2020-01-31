



import java.util.*;

public class T6365166 {
    static <A> void add(List<? super A> l, List<A> la) {
        l.addAll(la); 
    }
}

