

import java.util.List;

class T6985719b {
    abstract class A { abstract void f(List<String> ls); }
    interface B { void f(List<Integer> ls); }
    abstract class C extends A implements B {}
}
