



public class T6245699 {
    public static void main(String[] args) {
        Interface x = new Derived();
        x.method(); 
    }

    static interface Interface {
        public Base method();
    }

    static class Base {
        
        public final Derived method() { return null; }
    }

    static class Derived extends Base implements Interface {}
}
