
class TargetType44 {

    interface Unary {
        void m(int i1);
    }

    interface Binary {
        void m(int i1, int i2);
    }

    void m(Unary u) { }
    void m(Binary u) { }

    void test() {
        m(()-> { new Object() { }; }); 
        m(x -> { new Object() { }; }); 
        m((x, y) -> { new Object() { }; }); 
        m((x, y, z) -> { new Object() { }; }); 
    }
}
