



public class T4695847<T> {
    T4695847<T> next;
    static <T> int size(T4695847<T> bt) {
        if (bt==null)
            return 0;
        else
            return 1+size(bt.next);
    }
    static <T> int size2(T4695847<T> bt) {
        return (bt==null) ? 0 : 1+size(bt.next);
    }
}
