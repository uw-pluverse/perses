


class MostSpecific10 {

    interface GetInt {
        int get();
    }

    interface GetInteger {
        Integer get();
    }

    void m(GetInt getter) {}
    void m(GetInteger getter) {}

    void test(boolean cond) {
        m(() -> 23);
        m("abc"::length);
        m(( () -> 23 ));
        m(( "abc"::length ));
        m(cond ? () -> 23 : "abc"::length);
        m(( cond ? () -> 23 : "abc"::length ));
        m(cond ? (() -> 23) : ("abc"::length) );
        m(( cond ? () -> 23 : cond ? ("abc"::length) : (() -> 23) ));
    }

}
