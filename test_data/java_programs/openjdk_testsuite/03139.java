

class Test {

    interface IntMapper {
        int map();
    }

    interface LongMapper {
        long map();
    }

    void m(IntMapper im, LongMapper s) { }
    void m(LongMapper lm, IntMapper s) { }

    void test() {
        m(()->1, ()->1);
    }
}
