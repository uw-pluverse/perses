

class Test implements AutoCloseable {
    void test() {
        try(Test t = null) {}
    }
}
