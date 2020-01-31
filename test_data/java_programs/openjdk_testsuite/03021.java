



class LambdaExpr09 {

    interface Block<T> {
       void m(T t);
    }

    void apply(Object[] obj_arr) { }

    void test1() {
        Block<?>[] arr1 =  { t -> { }, t -> { } };
        Block<?>[][] arr2 =  { { t -> { }, t -> { } }, { t -> { }, t -> { } } };
    }

    void test2() {
        Block<?>[] arr1 =  new Block<?>[]{ t -> { }, t -> { } };
        Block<?>[][] arr2 =  new Block<?>[][]{ { t -> { }, t -> { } }, { t -> { }, t -> { } } };
    }

    void test3() {
        apply(new Block<?>[]{ t -> { }, t -> { } });
        apply(new Block<?>[][]{ { t -> { }, t -> { } }, { t -> { }, t -> { } } });
    }
}
