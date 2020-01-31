



package typaram.static_.scope2;

class JBug<T> {
    static class Inner1 implements Set<T> {}
}

interface Set<T> {}
