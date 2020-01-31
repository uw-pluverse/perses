



public class T6391995 {
    <E> void iterate(Iterable<E> iterable) {
        Iterable<? extends Iterable<? extends Object>> x = null;
        iterate(x.iterator().next());
    }
}
