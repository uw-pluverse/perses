
class TargetType66 {
    interface SAM1 {
        void m(String s);
    }

    interface SAM2 {
        void m(Integer s);
    }

    void g(SAM1 s1) { }
    void g(SAM2 s2) { }

    void test() {
        g(x->{ String s = x; }); 
        g(x->{ Integer i = x; }); 
        g(x->{ Object o = x; }); 
        g(x->{ Character c = x; }); 
        g(x->{ Character c = ""; }); 
    }
}
