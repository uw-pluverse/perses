



import java.lang.reflect.*;

public class StrictAbstract {

    static strictfp interface I {
        void f();
    }

    static abstract strictfp class C {
        void f() {}
        abstract void g();
    }

    static Class[] ca = new Class[0];

    public static void main(String[] args) throws Exception {
        check(I.class.getDeclaredMethod("f", ca));
        check(C.class.getDeclaredMethod("f", ca));
        check(C.class.getDeclaredMethod("g", ca));
    }
    static void check(Method m) throws Exception {
        int mask=Modifier.ABSTRACT | Modifier.STRICT;
        if ((m.getModifiers() & mask) == mask) throw new Error();
    }

}
