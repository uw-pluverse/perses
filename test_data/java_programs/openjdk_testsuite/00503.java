



public class Test<T> {
    <T extends Test<? super Number>> T m1(T t) {
        return m2(t);
    }
    <T extends Test<? super Number>> T m2(T t) {
        return null;
    }
}
