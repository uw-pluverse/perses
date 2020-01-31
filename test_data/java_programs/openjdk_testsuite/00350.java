



package Casting4;

class Casting4 {
    <M> Integer f(Comparable<M> c) {
        return (Integer) c;
    }
    Integer g(Comparable<?> c) {
        return (Integer) c;
    }
}
