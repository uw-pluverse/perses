



import java.util.Collection;
import java.util.Comparator;

public class CrashMethodReferenceWithSiteTypeVarTest {
    public <T> void m1(Collection<T> c, Comparator<T> comp) {}

    public <T extends Comparable> void m2(Collection<T> c) {
        m1(c, T::compareTo);
    }
}
