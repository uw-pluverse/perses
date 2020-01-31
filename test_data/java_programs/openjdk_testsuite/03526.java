

class DuplicateResourceDecl {

    public static void main(String[] args) {
        try(MyResource c = new MyResource();MyResource c = new MyResource()) {
        
        } catch (Exception e) { }
    }

    static class MyResource implements AutoCloseable {
        public void close() throws Exception {}
    }
}
