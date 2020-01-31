



import java.util.List;
import java.util.ArrayList;

public class InferenceTest4 {

    private static void assertTrue(boolean b) {
        if(!b)
            throw new AssertionError();
    }

    public static void main(String[] args) {
        InferenceTest4 test = new InferenceTest4();
        test.method1(n -> n.size(), "abc", "java.lang.String");
        test.method1(n -> n.size(), 'c', "java.lang.Character");
        test.method1(n -> n.size(), 0, "java.lang.Integer");
        test.method1(n -> n.size(), 0.1, "java.lang.Double");
        test.method1(n -> n.size(), 0.1f, "java.lang.Float");
        test.method1(n -> n.size(), 0L, "java.lang.Long");
        test.method1(n -> n.size(), (short)0, "java.lang.Short");
        test.method1(n -> n.size(), (byte)0, "java.lang.Byte");
        test.method1(n -> n.size(), true, "java.lang.Boolean");
        test.method1(n -> n.size(), new int[]{1, 2, 3}, "[I");
        test.method1(n -> n.size(), new double[]{1.0}, "[D");
        test.method1(n -> n.size(), new String[]{}, "[Ljava.lang.String;");
    }

    <T> void method1(SAM1<T> s, T t, String className) {
        List<T> list = new ArrayList<T>();
        System.out.println(className + "-" + t.getClass().getName());
        assertTrue(t.getClass().getName().equals(className));
        list.add(t);
        assertTrue(s.m1(list) == 1);
    }

    interface SAM1<T> {
        int m1(List<T> x);
    }
}
