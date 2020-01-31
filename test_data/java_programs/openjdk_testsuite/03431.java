



public class T6548436a {

    static class Base<E extends Comparable<E>> {}

    static void test(Base<?> je) {
        Object o = (Base<Integer>)je;
    }
}
