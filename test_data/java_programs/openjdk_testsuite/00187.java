

import java.util.List;

class T6985719h {
    abstract class A<X> { abstract void f(List<X> ls); }
    abstract class B extends A<String> { abstract void f(List<Integer> ls); }
}
