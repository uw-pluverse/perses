



class UnreportedExceptionImplicitClose {
    static class MyCloseable implements AutoCloseable {
        public void close() throws Exception { }
    }
    void test() {
        try (MyCloseable x = new MyCloseable()) {  }
    }
}
