
public class T6611449<S> {

    <T extends S> T6611449(T t1) {}

    <T extends S> T6611449(T t1, T t2) {}

    <T extends S> void m1(T t1) {}

    <T extends S> void m2(T t1, T t2) {}

    void test() {
        new T6611449<S>(1);
        new T6611449<S>(1, 1); 
        m1(1);
        m2(1, 1); 
    }
}
