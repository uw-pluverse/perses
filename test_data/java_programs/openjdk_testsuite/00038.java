

import java.util.*;

class T7062745neg {
    interface A { List<Number> getList(); }
    interface B { ArrayList getList(); }
    interface AB extends A, B {}

    void test(AB ab) {
        Number n = ab.getList().get(1);
    }
}
