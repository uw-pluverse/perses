

import java.util.Iterator;

class Test {
    <T> void test() {
        new Iterable<T>() {
            public Iterator<T> iterator() { return null; }
        };
    }
}
