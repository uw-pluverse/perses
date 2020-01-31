



import java.util.ArrayList;

public class DuplicateResource {

    static class TestResource implements AutoCloseable {
        TestResource() {
            resources.add(this);
        }
        boolean isClosed = false;
        public void close() throws Exception {
            isClosed = true;
        }
    }

    static ArrayList<TestResource> resources = new ArrayList<TestResource>();

    public static void main(String[] args) {
        try(TestResource tr = new TestResource()) {
           
        } catch (Exception e) {
            throw new AssertionError("Shouldn't reach here", e);
        }
        check();
    }

    public static void check() {
       if (resources.size() != 1) {
           throw new AssertionError("Expected one resource, found: " + resources.size());
       }
       TestResource resource = resources.get(0);
       if (!resource.isClosed) {
           throw new AssertionError("Resource used in try-with-resources block has not been automatically closed");
       }
    }
}
