

package a;

import java.util.Vector;

public class A {
    private class P {}
    public P p;
    public Vector<P> vec;
    public A() {
        vec = new Vector<P>();
        vec.add(new P());
    }
}
