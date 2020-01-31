

import java.util.List;

class T7177306a<A> {

    public static void test(List l) {
        T7177306a<Object> to = m(l);
    }

    public static <E> T7177306a<String> m(List<E> le) {
        return null;
    }
}
