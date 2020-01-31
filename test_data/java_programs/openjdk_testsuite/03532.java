

class ResourceOutsideTry {
    void test() {
        try(MyResource c = new MyResource()) {
        
        } catch (Exception e) {
            c.test();
        } finally {
            c.test();
        }
    }
    static class MyResource implements AutoCloseable {
        public void close() throws Exception {}
        void test() {}
    }
}
