

class T7015430 {
    static <E extends Exception> Iterable<E> empty(Iterable<E> arg) throws E {
        return null;
    }

    <E extends Exception> T7015430(Iterable<E> arg) throws E { }

    static <E extends Exception> Iterable<E> empty2(Iterable x) throws E {
        return null;
    }

    static class Foo<X extends Exception> {
        Foo() throws X {}
    }

    
    void m1() {
        Iterable<RuntimeException> i = java.util.Collections.emptyList();
        empty(i);
    }

    
    void m2() {
        Iterable i = java.util.Collections.EMPTY_LIST;
        empty(i);
    }

    
    void m3() {
        Iterable i = java.util.Collections.EMPTY_LIST;
        T7015430.<RuntimeException>empty(i);
    }

    
    void m4() {
        Iterable<RuntimeException> i = java.util.Collections.emptyList();
        new T7015430(i);
    }

    
    void m5() {
        Iterable i = java.util.Collections.EMPTY_LIST;
        new T7015430(i);
    }

    
    void m6() {
        Iterable i = java.util.Collections.EMPTY_LIST;
        new <RuntimeException>T7015430(i);
    }

    
    void m7() {
        Iterable i = java.util.Collections.EMPTY_LIST;
        Iterable<RuntimeException> e = empty2(i);
    }

    
    void m8() {
        Iterable i = java.util.Collections.EMPTY_LIST;
        empty2(i);
    }

    
    void m9() {
        Iterable i = java.util.Collections.EMPTY_LIST;
        new <RuntimeException> T7015430(i);
    }

    
    void m10() {
        Iterable i = java.util.Collections.EMPTY_LIST;
        new T7015430(i);
    }

    
    void m11() {
        Foo<RuntimeException>  o = new Foo<>();
    }

    
    void m12() {
        new Foo<>();
    }
}
