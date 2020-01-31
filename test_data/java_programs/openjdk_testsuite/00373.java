



import java.util.*;

class T {
    void f(Map<?,?> m) {
        for ( Map.Entry e : m.entrySet() ) { }
    }
}
class Box<T> {
    T get() { return null; }
}
class Main {
    public static void main(String[] args) {
        Box<? extends Integer> bi = null;
        int i = bi.get();
    }
}
