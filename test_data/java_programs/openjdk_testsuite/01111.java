





class CantRefNonEffectivelyFinalVar {
    void test() {
        int i = 0;
        new Object() { int j = i; };
        i = 2;
    }

    interface SAM {
        void m();
    }

    void test2() {
        int i = 0;
        SAM s = ()-> { int j = i; };
        i++;
    }
}
