



import java.util.*;

interface A {}
interface B<T> extends Iterable<T> {}
interface X {}

class C extends ArrayList<String> implements A, B<String> {
    C() {
        super(Arrays.<String>asList(new String[] {"Hello", "world"}));
    }
}

class D implements A, X {
    final String s;
    D(String s) {
        this.s = s;
    }
    public String toString() {
        return s;
    }
}

public class IntersectIterator {

    static
    <T extends A & B<String>>
    void f(T t) {
        for (String s : t) System.out.println(s);
    }
    static
    <T extends A & X>
    void f(Iterable<T> t) {
        for (A a : t) System.out.println(a);
        for (X x : t) System.out.println(x);
    }

    public static void main(String[] args) {
        f(new C());
        f(Arrays.<D>asList(new D[] {new D("Hello"), new D("world")}));
    }
}
