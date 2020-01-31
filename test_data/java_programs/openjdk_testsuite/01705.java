



public class GenericsAndTWRCompileErrorTest {

    public static class Resource<E extends Exception> implements AutoCloseable {
        public void close() throws E { }
    }

    public <E extends Exception> void test() throws E {
        try (Resource<E> r = new Resource<E>()) {

        }
    }
}
