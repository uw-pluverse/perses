



class T6650759a {

    public static interface Interface<T> { }
    public static class IntegerInterface implements Interface<Integer> { }

    <I extends Interface<T>, T> T getGenericValue(I test) { return null; }

    void testSet(Integer test) { }

    void test() {
        Integer test = getGenericValue(new IntegerInterface());
        testSet(getGenericValue(new IntegerInterface()));
    }
}
