



import java.util.List;

public abstract class WildcardAndCAPSubtypeTest {
    abstract <T> List<T> copyOf(List<? extends T> lx);
    abstract <E> List<E> filter(List<E> lx);

    void g(List<?> lx) {
        copyOf(filter(lx));
    }
}
