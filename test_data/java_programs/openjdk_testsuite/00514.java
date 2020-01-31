



public class T6245699b {
    public static void main(String[] args) {
        IBar b = new Bar();
        String x = b.doIt();
    }

    static class Foo<T> {
        public final T doIt() { return null; }
    }

    static interface IBar {
        String doIt();
    }

    static class Bar extends Foo<String> implements IBar {
        public String doIt() { 
            return null;
        }
    }
}
