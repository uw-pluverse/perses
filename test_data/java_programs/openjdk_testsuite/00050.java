



import java.util.Collection;
import java.util.List;

public class T6476073 {
    public static <B> void m(List<? super B> list,Collection<? super B> coll) {
        m(list,coll);
    }
}
