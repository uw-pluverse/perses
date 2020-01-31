
class FunctionalInterfaceAnno {
    @FunctionalInterface
    static class A { } 

    @FunctionalInterface
    static abstract class B { } 

    @FunctionalInterface
    enum C { } 

    @FunctionalInterface
    @interface D { } 

    @FunctionalInterface
    interface E { } 

    @FunctionalInterface
    interface F { default void m() { } } 

    @FunctionalInterface
    interface G { String toString(); } 

    @FunctionalInterface
    interface H { void m(); void n(); } 

    @FunctionalInterface
    interface I { void m(); } 
}
