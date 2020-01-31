

class CrashFunctionDescriptorExceptionTest {

    @SuppressWarnings("unchecked")
    void m () {
        bar((B b) -> {});
    }

    <E extends A<E>> void bar(I<E> i) {}

    class A<E> {}

    class B<E> extends A<E> {}

    interface I<E extends A<E>> {
        void foo(E e);
    }
}
