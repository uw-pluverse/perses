


class T6747671b {

    sun.misc.Lock a1; 

    @SuppressWarnings("sunapi")
    sun.misc.Lock a2;

    <X extends sun.misc.Lock> sun.misc.Lock m1(sun.misc.Lock a)
            throws sun.misc.CEFormatException { return null; } 

    @SuppressWarnings("sunapi")
    <X extends sun.misc.Lock> sun.misc.Lock m2(sun.misc.Lock a)
            throws sun.misc.CEFormatException { return null; }

    void test() {
        sun.misc.Lock a1; 

        @SuppressWarnings("sunapi")
        sun.misc.Lock a2;
    }
}
