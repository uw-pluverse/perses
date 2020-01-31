

import java.util.List;

class T6985719d {
    abstract class A { abstract void f(List<String> ls); }
    interface B<X> { void f(List<X> ls); }
    abstract class C extends A implements B<Integer> {}
}
