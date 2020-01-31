



import java.util.*;

public class BoxedForeach {
    static void f(Integer[] a) {
        for ( int i : a ) {
            System.out.println(i);
        }
    }
    static void f(Iterable<Integer> b) {
        g(b);
        h(b);
        for ( int i : b ) {
            System.out.println(i);
        }
        for ( float i : b ) {
            System.out.println(i);
        }
        for ( Iterator<Integer> it = b.iterator(); it.hasNext(); ) {
            float i = it.next();
        }
    }
    static <T extends Integer> void g(Iterable<T> b) {
        for ( int i : b ) {
            System.out.println(i);
        }
    }
    static void h(Iterable<? extends Integer> b) {
        for ( int i : b ) {
            System.out.println(i);
        }
    }
    static void f(int[] c) {
        for ( Integer i : c ) {
            System.out.println(i);
        }
    }
    static <E extends Enum<E>> void f(E[] values) {
        for ( E e : values ) {
            System.out.println(e);
        }
    }
    static int f() {
        for ( Foo f : foolist() ) {
            return f.x;
        }
        return 0;
    }
    static List<Foo> foolist() {
        List<Foo> l = new ArrayList<Foo>();
        l.add(new Foo());
        return l;
    }
    enum color { red, green, blue };
    public static void main(String[] args) {
        Integer[] a1 = { Integer.valueOf(1), Integer.valueOf(2) };
        f(a1);
        f(Arrays.asList(a1));
        int[] a2 = { 1, 2, 3 };
        f(a2);
        f(color.values());
        f();
    }
}

class Foo {
    static int n = 0;
    final int x;
    Foo() {
        x = n++;
    }
}

class A {
    class B {
    }
    java.util.List<String> l;
    String[] args;
    {
        for (String s1 : l) {
            for (String s2 : l) {
                B b = new B();
            }
        }
        for (String s1 : args) {
            for (String s2 : args) {
                B b = new B();
            }
        }
    }
}
