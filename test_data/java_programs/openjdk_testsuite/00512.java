



public class T6245699c {
    public static void main(String[] args) {
        Interface x = new Derived();
        x.method("blah"); 
    }

    static interface Interface {
        void method(String arg);
    }

    static class Base<T> {
        public final void method(T arg) {}
    }

    static class Derived extends Base<String> implements Interface {}
}
