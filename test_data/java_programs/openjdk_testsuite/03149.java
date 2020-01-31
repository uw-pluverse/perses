
class MostSpecific14 {
    interface ToNumber { Number get(); }
    interface ToToNumber { ToNumber get(); }
    interface Factory<T> { T get(); }

    void m1(Factory<Factory<Object>> f) {}
    void m1(ToToNumber f) {}

    void m2(Factory<Factory<Number>> f) {}
    void m2(ToToNumber f) {}

    void m3(Factory<Factory<Integer>> f) {}
    void m3(ToToNumber f) {}


    void test() {
        m1(() -> () -> 23); 
        m2(() -> () -> 23); 
        m3(() -> () -> 23); 

        m1(() -> this::getInteger); 
        m2(() -> this::getInteger); 
        m3(() -> this::getInteger); 
    }

    Integer getInteger() { return 23; }
}
