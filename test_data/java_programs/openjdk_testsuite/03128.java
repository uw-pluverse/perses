
import java.util.*;

class BadMethodCall {
    <I> List<I> id(List<I> z) { return null; };

    List<String> cons(String s, List<String> ls) { return null; }

    void test(List<Object> lo) { Object t = cons(id(""),lo); }
}
