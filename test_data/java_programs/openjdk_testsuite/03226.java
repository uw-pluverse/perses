



import org.testng.annotations.Test;
import java.lang.reflect.Array;

import static org.testng.Assert.assertEquals;
import static org.testng.Assert.assertTrue;
import static org.testng.Assert.fail;



@Test
@SuppressWarnings({"rawtypes", "unchecked"})
public class MethodReferenceTestFDCCE {

    static void assertCCE(Throwable t) {
        assertEquals(t.getClass().getName(), "java.lang.ClassCastException");
    }

    interface Pred<T> { boolean accept(T x); }

    interface Ps { boolean accept(short x); }

    interface Oo { Object too(int x); }

    interface Reto<T> { T m(); }

    class A {}
    class B extends A {}

    static boolean isMinor(int x) {
        return x < 18;
    }

    static boolean tst(A x) {
        return true;
    }

    static Object otst(Object x) {
        return x;
    }

    static boolean stst(Short x) {
        return x < 18;
    }

    static short ritst() {
        return 123;
    }

    public void testMethodReferenceFDPrim1() {
        Pred<Byte> p = MethodReferenceTestFDCCE::isMinor;
        Pred p2 = p;
        assertTrue(p2.accept((Byte)(byte)15));
    }

    public void testMethodReferenceFDPrim2() {
        Pred<Byte> p = MethodReferenceTestFDCCE::isMinor;
        Pred p2 = p;
        assertTrue(p2.accept((byte)15));
    }

    public void testMethodReferenceFDPrimICCE() {
        Pred<Byte> p = MethodReferenceTestFDCCE::isMinor;
        Pred p2 = p;
        try {
            p2.accept(15); 
            fail("Exception should have been thrown");
        } catch (Throwable t) {
            assertCCE(t);
        }
    }

    public void testMethodReferenceFDPrimOCCE() {
        Pred<Byte> p = MethodReferenceTestFDCCE::isMinor;
        Pred p2 = p;
        try {
            p2.accept(new Object()); 
            fail("Exception should have been thrown");
        } catch (Throwable t) {
            assertCCE(t);
        }
    }

    public void testMethodReferenceFDRef() {
        Pred<B> p = MethodReferenceTestFDCCE::tst;
        Pred p2 = p;
        assertTrue(p2.accept(new B()));
    }

    public void testMethodReferenceFDRefCCE() {
        Pred<B> p = MethodReferenceTestFDCCE::tst;
        Pred p2 = p;
        try {
            p2.accept(new A()); 
            fail("Exception should have been thrown");
        } catch (Throwable t) {
            assertCCE(t);
        }
    }

    public void testMethodReferenceFDPrimPrim() {
        Ps p = MethodReferenceTestFDCCE::isMinor;
        assertTrue(p.accept((byte)15));
    }

    public void testMethodReferenceFDPrimBoxed() {
        Ps p = MethodReferenceTestFDCCE::stst;
        assertTrue(p.accept((byte)15));
    }

    public void testMethodReferenceFDPrimRef() {
        Oo p = MethodReferenceTestFDCCE::otst;
        assertEquals(p.too(15).getClass().getName(), "java.lang.Integer");
    }

    public void testMethodReferenceFDRet1() {
        Reto<Short> p = MethodReferenceTestFDCCE::ritst;
        assertEquals(p.m(), (Short)(short)123);
    }
}
