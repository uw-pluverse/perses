



import java.util.*;

public class Pos01 {

    interface Mapper<T> {
        T map(T in);
    }

    interface ExtendedList<T> extends List<T> {
        default List<T> testMap(Mapper<T> r) {
            return Pos01.<T>listMapper(this, r);
        }
    }

    static class MyList<E> extends ArrayList<E> implements ExtendedList<E> {}

    public static void main(String[] args) {
       MyList<Integer> l = new MyList<Integer>();
       l.add(1); l.add(2); l.add(3);
       l.testMap((Integer x) -> x * x );
    }

    static <T> List<T> listMapper(List<T> l, Mapper<T> mapper) {
        MyList<T> new_list = new MyList<T>();
        for (T el : l) {
            new_list.add(mapper.map(el));
        }
        return new_list;
    }
}
