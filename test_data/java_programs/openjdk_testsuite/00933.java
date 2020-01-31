



import java.util.List;

public class T6682380<X> {

    public static void main(String[] args) {
        try {
        } finally {
            List<T6682380<?>> l = null;
            T6682380<?>[] a = null;
            for (T6682380<?> e1 : l);
            for (T6682380<?> e2 : a);
        }
    }
}
