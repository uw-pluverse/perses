



import java.util.List;

public class T6268476 {
    void foo(List<? super Object[]> l) {
        l.add(new Object[0]);
    }
}
