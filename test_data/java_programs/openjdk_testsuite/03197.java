
public interface TBlock<T> {

    
    void apply(T t);

    
    public default TBlock<T> chain(TBlock<? super T> other) {
        return (T t) -> { apply(t); other.apply(t); };
    }
}
