

class T6569404b {

    static class A<X> {}

    static class B<T extends Outer> extends A<T.Inner> {}

    static class Outer {
        public class Inner {}
    }
}
