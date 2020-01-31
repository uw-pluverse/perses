


class NestedCapture03 {
    <T extends String> T factory(Class<T> c) { return null; }

    void test(Class<?> c) {
        factory(c.asSubclass(String.class)).matches(null);
    }
}
