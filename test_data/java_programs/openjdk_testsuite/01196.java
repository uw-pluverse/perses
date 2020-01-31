






import java.util.List;

class IncompatibleUpperBounds {
    <S> void m(List<? super S> s1, List<? super S> s2) { }
    void m(Object o) {}

    void test(List<Integer> li, List<String> ls) {
        m(li, ls);
    }
}
