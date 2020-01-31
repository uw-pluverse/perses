




class PotentiallyAmbiguousOverload {
    interface F1 {
        void m(String s);
    }

    interface F2 {
        void m(Integer s);
    }

    void m(F1 f1) { }
    void m(F2 f2) { }
}
