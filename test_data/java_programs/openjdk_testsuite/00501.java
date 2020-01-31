



import java.util.*;

class T7020657pos {
    interface A {
        int get(List<String> l);
    }

    interface B  {
        int get(List<Integer> l);
    }

    interface C extends A, B {
        int get(List l);
    }
}
