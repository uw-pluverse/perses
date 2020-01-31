
class MostSpecific13 {

    interface UnaryOp<T> { T apply(T arg); }
    interface IntegerToNumber { Number apply(Integer arg); }

    <T> void m(UnaryOp<T> f) {}
    void m(IntegerToNumber f) {}

    void test() {
        m((Integer i) -> i); 
        m(this::id); 
    }

    Integer id(Integer arg) { return arg; }
}
