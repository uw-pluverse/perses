



abstract public class T5049523 {
    abstract <T> T choose(boolean b, T t1, T t2);
    abstract <T> Class<? extends T> m(Class<T> c);

    <T> void test(Class<? extends T> clazz) {
        boolean b = clazz.isInterface();
        Class<? extends T> c1 = b ? m(clazz) : clazz;
        Class<? extends T> c2 = choose(b, m(clazz), clazz);
    }
}
