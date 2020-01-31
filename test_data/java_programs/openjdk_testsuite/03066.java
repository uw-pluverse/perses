

class Test {

    interface IntMapper {
        int map();
    }

    interface LongMapper {
        long map();
    }

    void m(IntMapper... im) { }
    void m(LongMapper... lm) { }

    void m2(IntMapper im1, IntMapper... im) { }
    void m2(LongMapper... lm) { }

    void test1() {
        m(); 
        m(()->1); 
        m(()->1, ()->1); 
        m(()->1, ()->1, ()->1); 
    }

    void test2() {
        m(null, null); 
        m(()->1, null); 
        m(null, ()->1); 
        m(()->1L, null); 
        m(null, ()->1L); 
    }

    void test3() {
        m2(); 
        m2(()->1); 
        m2(()->1, ()->1); 
        m2(()->1, ()->1, ()->1); 
    }

    void test4() {
        m2(null, null, null); 
        m2(()->1, null, null); 
        m2(null, ()->1, null); 
        m2(null, null, ()->1); 
        m2(()->1, ()->1, null); 
        m2(null, ()->1, ()->1); 
        m2(()->1, null, ()->1); 

        m2(()->1L, null, null); 
        m2(null, ()->1L, null); 
        m2(null, null, ()->1L); 
        m2(()->1L, ()->1L, null); 
        m2(null, ()->1L, ()->1L); 
        m2(()->1L, null, ()->1L); 
    }
}
