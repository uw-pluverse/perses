

@TraceResolve(keys={"compiler.err.cant.apply.symbol"})
class Test {

    
    void m(Integer i1, Integer i2) { }

    
    void m(Object... o) { }

    class Inner {
        @Candidate
        void m(String s) {
            m(1, 1); 
        }
    }
}
