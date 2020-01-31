



package rare7;

class A<T> {
    class B<U> {
        T t;
    }

    static class C {
        {
            B<String> b = null;
        }
    }
}
