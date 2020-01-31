


class TargetType37 {

    interface I { }

    void test(Object o, boolean cond) {
        I i = (I)(cond ? o : o);
    }
}
