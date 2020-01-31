

class T6985719a {
    class AX<T extends Number> {
        void foo(T t) { }
    }

    class BX<S extends Integer> extends AX<S> {
        @Override
        void foo(S t) { }
        void bar(BX bx){}
    }

    class DX extends BX<Integer> {
        void foo(Number t) { }
        void bar(BX<?> bx) { }

        @Override
        void foo(Integer t) { }
    }
}
