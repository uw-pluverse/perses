



import java.util.*;

class T6558559b {
    void test(List rawList, List<?> unboundList) {
        Throwable t0 = (Throwable) Collections.emptyList();
        Throwable t1 = (Throwable) rawList;
        Throwable t2 = (Throwable) unboundList;
        Object o = unboundList;
        Throwable t3 = (Throwable) o;
    }
}
