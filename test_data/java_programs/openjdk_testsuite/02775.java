

class T6717241a<X extends Object & java.io.Serializable> {
    X x;
    void test() {
        
        Object o = x.v;
        
        x.m1(1, "");
        
        x.<Integer,Double>m2(1, "");
    }
}
