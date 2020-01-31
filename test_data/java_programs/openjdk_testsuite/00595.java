



public class WhichImplicitThis10 {
    static class A {
        class Inner {}
    }

    static class B extends A {
        class Inner extends A.Inner {
            public Inner() {
                
                
                super();
            }
        }
    }
}
