

class LambdaExpr10 {

    interface Block<T> {
       void m(T t);
    }

    void apply(Object[] obj_arr) { }

    void test1() {
        Object[] arr1 =  { t -> { } };
        Object[][] arr2 =  { { t -> { } } };
    }

    void test2() {
        Object[] arr1 =  new Object[]{ t -> { } };
        Object[][] arr2 =  new Object[][]{ { t -> { } } };
    }

    void test3() {
        apply(new Object[]{ t -> { } });
        apply(new Object[][]{ { t -> { } } });
    }

    void test4() {
        Block<?>[] arr1 =  { t -> t };
        Block<?>[] arr2 =  new Block<?>[]{ t -> t };
        apply(new Block<?>[]{ t -> { }, t -> { } });
    }
}
