



package pack1;

public class P1 {

    public P1() {}

    protected P1(String s) {}

    public P2 p2 = new P2();

    
    class P3 {
        
        
        public class P4 {
            
            class P5 {}
        }
    }

    static class Foo {
        public static class Bar {}
    }

    public Foo a[] = null;

    protected static class Q {
        protected Q (String s) {}
    }

    protected static class R {
        private static class S {
            public static class T {}
        }
    }
}
