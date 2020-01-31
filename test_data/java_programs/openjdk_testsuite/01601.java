



import java.util.*;

class Conditional {
    void test() {
        String[] sa = null;
        List<String> ls = sa == null ? Arrays.asList(sa) :
            Collections.emptyList();
    }
}
