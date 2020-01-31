




import java.util.List;

class IncompatibleEqUpperBounds {
    <S, T extends List<S>> void m(List<? super S> s1, T s2) { }

    void test(List<Integer> li, List<String> ls) {
        m(li, ls);
    }
}
