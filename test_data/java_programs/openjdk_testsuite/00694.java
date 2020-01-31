

@TraceResolve(keys={"compiler.err.ref.ambiguous"})
class AmbiguityPrecedence {

    @Candidate(applicable=Phase.BASIC)
    static void m1(long l, int i) {}
    @Candidate(applicable=Phase.BASIC)
    static void m1(int i, long l) {}
    @Candidate
    static void m1(Integer i1, Integer i2) {}

    @Candidate(applicable=Phase.BOX)
    static void m2(Object o, Integer i) {}
    @Candidate(applicable=Phase.BOX)
    static void m2(Integer i, Object o) {}
    @Candidate
    static void m2(Integer... o) {}

    {
        m1(1, 1);
        m2(1, 1);
    }
}
