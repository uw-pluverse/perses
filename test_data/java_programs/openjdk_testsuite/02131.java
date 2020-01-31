



package varargs.warning.warn1;

import java.util.List;
import java.util.Arrays;

class Warn1 {
    void f(String[] args) {
        List l = java.util.Arrays.asList(args);
    }
}
