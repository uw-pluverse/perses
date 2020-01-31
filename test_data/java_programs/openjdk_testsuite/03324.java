

import java.util.Collection;
import java.util.List;

public class NonSAM3 {
    void method() {
        
        FooBar fb = (Number n) -> 100;
        FooBar fb2 = (Integer i) -> 100;
        DE de = (List<Integer> list) -> 100;
        DE de2 = (List<?> list) -> 100;
        DE de3 = (List list) -> 100;
        DE de4 = (Collection<Integer> collection) -> 100;
        DE de5 = (Collection<?> collection) -> 100;
        DE de6 = (Collection collection) -> 100;
    }
}
