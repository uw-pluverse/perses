



package conditional;

import java.io.Serializable;

interface I {}
interface J {}
class A implements I, J {}
class B implements I, J {}
class C extends B {}

class Conditional {
    static boolean cond = String.class.getName().length() == 1;
    public static void main(String[] args) {
        Class c = cond ? A.class : B.class;
        Class<?> d = cond ? A.class : B.class;

        Class<? extends B> e = cond ? B.class : C.class;
    }

    void f(A a, B b) {
        I i = cond ? a : b;
        J j = cond ? a : b;
    }

    
    Class g(Class a) {
        return cond ? a : B.class;
    }

    
    byte[] h(byte[] a, byte[] b) {
        return cond ? a : b;
    }

    
    
    
    
    Class<? extends Comparable<?>> c =
        cond ? Integer.class : Float.class;

    Comparable<?> o =
        cond ? true : 3;

    
}
