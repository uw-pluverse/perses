

import java.util.List;

class Bar {

    private class Foo { }

    <Z> List<Z> m(Object... o) { return null; }
    <Z> List<Z> m(Foo... o) { return null; }

    Foo getFoo() { return null; }
}

public class T7175433 {

    public static void main(String[] args) {
        Bar b = new Bar();
        b.m(b.getFoo());
    }
}
