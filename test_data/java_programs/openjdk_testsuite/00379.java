


class T7034495 {

    interface A<T> {
        T foo();
    }

    interface B<T> {
        T foo();
    }

    interface C<T extends A<?> & B<?>> { }

}
