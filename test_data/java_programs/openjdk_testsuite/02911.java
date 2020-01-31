

import java.util.*;

public class InferenceTest6 {
    public static void main(String[] args) {
        InferenceTest6 test = new InferenceTest6();
        test.method1(n -> {});
        test.method1((SAM1<String>)n -> {});
        test.method1((SAM1<Integer>)n -> {n++;});
        test.method1((SAM1<Comparator<String>>)n -> {List<String> list = Arrays.asList("string1", "string2"); Collections.sort(list,n);});
        test.method1((SAM1<Thread>)n -> {n.start();});
    }

    interface SAM1<X> {
        void m1(X arg);
    }

    <X> void method1(SAM1<X> s) {}
}
