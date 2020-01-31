
class TestNoDuplicateBridges02 {
    interface A<T> {
        A<T> get();
    }

    @Bridge("get()LTestNoDuplicateBridges02$A;")
    interface B<T> extends A<T> {
        B<T> get();
    }

    @Bridge("get()LTestNoDuplicateBridges02$A;")
    @Bridge("get()LTestNoDuplicateBridges02$B;")
    interface C<T> extends A<T>, B<T> {
        C<T> get();
    }
}
