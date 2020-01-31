

public class MethodNeg {
    <A extends D, D extends E, E extends B, B extends C, C extends C1, C1 extends B> void m(E e, D d) {
        m(e, d);
        m(null, null);
    }
}
