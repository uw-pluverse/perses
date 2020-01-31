



class MethodReference02 {
    static interface SAM {
       void m(Integer i);
    }

    void m(Integer i) {}
    void m(Double d) {}

    SAM s = this::m; 
}
