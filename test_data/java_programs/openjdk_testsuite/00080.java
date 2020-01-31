



class PrimitiveTypeInBoundForMethodRefTest {

    interface Mapper<T, U> {
        U map(T t);
    }

    static <U> Iterable<U> map(Mapper<String, U> mapper) {
        return null;
    }

    static void test() {
        Iterable<Integer> map = map(PrimitiveTypeInBoundForMethodRefTest::length);
    }

    public static <T> int length(String s) {
        return 0;
    }
}
