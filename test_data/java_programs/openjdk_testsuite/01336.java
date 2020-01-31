





class NotDefPublicCantAccessFragment {
    interface SAM {
        void m();
    }

    void test (p.C c) {
        SAM s = c::m;
    }
}
