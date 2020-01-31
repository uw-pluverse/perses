



import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;



interface IDSs { String m(String a); }

interface InDefA {
    default String xsA__(String s) {
        return "A__xsA:" + s;
    }

    default String xsAB_(String s) {
        return "AB_xsA:" + s;
    }

}

interface InDefB extends InDefA {

    default String xsAB_(String s) {
        return "AB_xsB:" + s;
    }

    default String xs_B_(String s) {
        return "_B_xsB:" + s;
    }
}

@Test
public class MethodReferenceTestInnerDefault implements InDefB {

    public void testMethodReferenceInnerDefault() {
        (new In()).testMethodReferenceInnerDefault();
    }

    class In {

        public void testMethodReferenceInnerDefault() {
            IDSs q;

            q = MethodReferenceTestInnerDefault.this::xsA__;
            assertEquals(q.m("*"), "A__xsA:*");

            q = MethodReferenceTestInnerDefault.this::xsAB_;
            assertEquals(q.m("*"), "AB_xsB:*");

            q = MethodReferenceTestInnerDefault.this::xs_B_;
            assertEquals(q.m("*"), "_B_xsB:*");
        }
    }

}
