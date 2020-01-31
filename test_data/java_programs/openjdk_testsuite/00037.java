



import java.util.*;

class T7062745pos {
    interface A { List<Number> getList(); }
    interface B { List getList(); }
    interface AB extends A, B {}

    void test(AB ab) {
        Number n = ab.getList().get(1);
    }
}
