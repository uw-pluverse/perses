



import java.util.ArrayList;
import java.util.List;

public class MultipleUpperBoundsIncorporationTest {

    static class TestCase1 {
        interface Task<E extends Exception> {}

        class Comparator<T> {}

        class CustomException extends Exception {}

        class TaskQueue<E extends Exception, T extends Task<E>> {}

        abstract class Test {
            abstract <E extends Exception, T extends Task<E>> TaskQueue<E, T> create(Comparator<? super T> comparator);

            void f(Comparator<Task<CustomException>> comp) {
                TaskQueue<CustomException, Task<CustomException>> queue = create(comp);
                queue.getClass();
            }
        }
    }

    static class TestCase2 {
        public <T, E extends List<T>> E typedNull() {
            return null;
        }

        public void call() {
            ArrayList<String> list = typedNull();
        }
    }

    static class TestCase3 {
        interface I extends Iterable<String> {}

        <T, Exp extends Iterable<T>> Exp typedNull() { return null; }
        I i = typedNull();
    }

}
