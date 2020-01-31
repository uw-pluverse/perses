



public class T5064736 {
    class A {}
    class B extends A {}

    public class Foo<T> {
        public <U extends B> void foo(Foo<? super A> param) {
            Foo<U> foo = (Foo<U>)param;
        }
    }
}
