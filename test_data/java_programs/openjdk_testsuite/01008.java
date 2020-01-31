



package capture5;

interface R<T extends R<T>> {}
class A implements R<A> {}
class B<T> implements R<B<T>> {}
class C implements R<C> {}

class Recursive {
    <t> t choose(t x, t y) {
        return x;
    }
    void f(boolean b1, boolean b2, boolean b3, A a, B<String> b, C c) {
        R<? extends R<? extends R<? extends R<? extends R<?>>>>> r = null;
        r = b2 ? a : b;
        r = b1 ? (b2 ? a : b) : (b3 ? b : c);
        r = choose(a,c);
        r = choose(choose(a,b), choose(b,c));
    }
}
