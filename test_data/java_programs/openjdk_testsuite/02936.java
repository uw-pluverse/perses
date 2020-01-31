



public class NPEMethodReferenceAndGenericsTest {
    public <T> void foo(java.util.Comparator<? super T> comparator) {}

    public <C extends Comparable<? super C>> void foo() {
        foo(C::compareTo);
    }
}
