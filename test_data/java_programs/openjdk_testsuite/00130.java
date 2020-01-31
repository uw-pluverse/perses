



public class T4972073b {

    static class D {}

    static interface MyInterface<E> {
        public String foo();
    }

    static class MyClass {}

    static class B<E extends MyClass & MyInterface<E> & MyInterface<E>> extends D {}

}
