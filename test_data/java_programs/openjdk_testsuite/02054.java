



package pck;

import static pck.T6392998.B.C;
import static pck.T6392998.B.*;

public class T6392998 {
    public static class A {
        public enum C { FOO; }
        public static Object C() { return null; }
        public enum D { FOO; }
        public static Object D() { return null; }
    }
    public static class B extends A {}
    Object o = C.FOO;
    Object p = C();
    Object q = D.FOO;
    Object r = D();
}
