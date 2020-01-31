



package rare1;

class A<T> {
    class B<U> {
    }
    static class C<V> {
    }
}

class Main {
    A<String>.B<Integer> ab1;
    A.B ab2;
    A.C<String> ac1;
    A.C ac2;
}
