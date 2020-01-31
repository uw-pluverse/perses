



public class ResourceNameConflict implements AutoCloseable {

    static final String str = "asdf";

    void test1() {
        String tr = "A resource spec var cannot have same name as local var.";
        try (ResourceNameConflict tr = new ResourceNameConflict()) {
        }
    }

    void test2(String... strArray) {
        for (String str : strArray) {
            try (ResourceNameConflict str = new ResourceNameConflict()) {
            }
        }
    }

    @Override
    public void close() {
    }
}

