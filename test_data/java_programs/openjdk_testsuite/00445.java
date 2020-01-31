


public class T8064803 {
    interface ParentA<T> {
        T process() throws Exception;
    }

    interface ParentB<T> {
        T process() throws Exception;
    }

    interface Child<T> extends ParentA<T>, ParentB<T> { }

    static class ChildImpl<T> implements Child<T> {
        @Override
        public T process() {
            return null;
        }
    }

    public static void main(String[] args) throws Exception {
        Child<String> child = new ChildImpl<String>();
        child.process();
    }
}
