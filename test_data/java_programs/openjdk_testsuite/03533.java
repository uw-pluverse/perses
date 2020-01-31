



class ResourceTypeVar<X extends AutoCloseable> {

    public void test() {
        try(X armflow = getX()) {
            
        } catch (Exception e) { 
            throw new AssertionError("Shouldn't reach here", e);
        }
    }

    X getX() { return null; }
}
