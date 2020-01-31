



import java.util.*;

class Conditional01 {
    void varargs(Object ... args) {  }

    void test(boolean flag, List<String> ls) {
       varargs(flag ? "" : ls);
       varargs(null, flag ? "" : ls);
       varargs(flag ? "" : ls());
       varargs(null, flag ? "" : ls());
    }

    List<String> ls() { return null; }
}
