

package pkg;

public interface Foo  {
    default void m1() { Impl.m1(this); }
    default void m2() { Impl.m2(this); }
}

class Impl {
    static void m1(Foo f) { }
    static void m2(Foo f) { }
}
