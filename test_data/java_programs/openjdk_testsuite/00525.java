



package typaram.static_.scope;

import java.util.Set;

class JBug<T> {
    abstract class Inner1 implements Set<T> { }
    static class Inner2<U> {
        class Inner3 { U z; }

        abstract class Inner4 implements Set<U> { }
    }
}
