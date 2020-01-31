
import java.util.*;

class MethodReference67 {
    interface Foo<X> {
        void m(List<X> lx, X x);
    }

    void test() {
        Foo<String> fs1 = List::add; 
        Foo fs2 = List::add;
    }
}
