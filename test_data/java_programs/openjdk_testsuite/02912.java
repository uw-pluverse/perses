

public class InferenceTest_neg1_2 {

    public static void main(String[] args) {
        InferenceTest_neg1_2 test = new InferenceTest_neg1_2();
        test.method(n -> null); 
        test.method(n -> "a"); 
        test.method(n -> 0); 
    }

    void method(SAM1 s) { 
        Integer i = s.foo("a");
    }

    void method(SAM2 s) { 
        String str = s.foo(0);
    }

    void method(SAM3<Integer> s) { 
        Integer i = s.get(0);
    }

    void method(SAM4<Double, String> s) { 
        String str = s.get(0.0);
    }

    void method(SAM5<Integer> s) { 
        Integer i = s.get(0.0);
    }

    interface SAM1 {
        Integer foo(String a);
    }

    interface SAM2 {
        String foo(Integer a);
    }

    interface SAM3<T> {
        T get(T t);
    }

    interface SAM4<T, V> {
        V get(T t);
    }

    interface SAM5<T> {
        T get(Double i);
    }
}
