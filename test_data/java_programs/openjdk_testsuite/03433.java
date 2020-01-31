



public class T6548436d {

    static class Base<E extends Comparable<E>> {}

    static void test(Base<? extends Double> je) {
        Object o = (Base<Integer>)je;
    }
}
