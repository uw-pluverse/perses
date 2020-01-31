





class BadArgTypesInLambda {
    interface SAM {
        void m(Integer i);
    }

    void g(SAM s) { }

    void test() {
        g(x->{ String s = x; });
    }
}
