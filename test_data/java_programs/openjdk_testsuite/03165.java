


class NestedCapture02<S,T> {

     <S,T> NestedCapture02<S,T> create(NestedCapture02<? super S,?> first,
             NestedCapture02<? super S, T> second) {
         return null;
     }

     <U> NestedCapture02<S, ? extends U> cast(Class<U> target) { return null; }

     <U> NestedCapture02<S, ? extends U> test(Class<U> target,
             NestedCapture02<? super S, ?> first, NestedCapture02<? super S, T> second) {
        return create(first, second.cast(target));
     }
}
