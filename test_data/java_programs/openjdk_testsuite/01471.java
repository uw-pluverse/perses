





class ConditionalTargetCantBeVoid {

    interface SAM {
        void m();
    }

    void test(boolean cond, Object o1, Object o2) {
        SAM s = ()-> cond ? o1 : o2;
    }
}
