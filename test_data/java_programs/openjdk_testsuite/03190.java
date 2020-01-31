
class BadRecovery {

    interface SAM1 {
        void m(Object o);
    }

    void m(SAM1 m) { };

    void test() {
        m((receiver, t) -> { receiver.someMemberOfReceiver(()->{ Object x = f; }); });
    }
}
