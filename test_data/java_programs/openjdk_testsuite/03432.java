



public class T6548436c {

    interface A<T extends A<? super T>> { }

    interface B extends A<B> { }

    static void test(A<?> a) {
        Object o = (B)a;
    }
}
