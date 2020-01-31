



import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;



class MethodReferenceTestTypeConversion_E<T> {
    T xI(T t) { return t; }
}

@Test
public class MethodReferenceTestTypeConversion {

    interface ISi { int m(Short a); }

    interface ICc { char m(Character a); }

    public void testUnboxObjectToNumberWiden() {
        ISi q = (new MethodReferenceTestTypeConversion_E<Short>())::xI;
        assertEquals(q.m((short)77), (short)77);
    }

    public void testUnboxObjectToChar() {
        ICc q = (new MethodReferenceTestTypeConversion_E<Character>())::xI;
        assertEquals(q.m('@'), '@');
    }

}
