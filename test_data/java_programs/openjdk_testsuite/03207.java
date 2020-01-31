



import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;



interface DSPRI { String m(String a); }

interface DSPRA {
    default String xsA__(String s) {
        return "A__xsA:" + s;
    }

    default String xsAB_(String s) {
        return "AB_xsA:" + s;
    }

}

interface DSPRB extends DSPRA {

    default String xsAB_(String s) {
        return "AB_xsB:" + s;
    }

    default String xs_B_(String s) {
        return "_B_xsB:" + s;
    }

}

@Test
public class MethodReferenceTestSuperDefault implements DSPRB {

    public void testMethodReferenceSuper() {
        DSPRI q;

        q = DSPRB.super::xsA__;
        assertEquals(q.m("*"), "A__xsA:*");

        q = DSPRB.super::xsAB_;
        assertEquals(q.m("*"), "AB_xsB:*");

        q = DSPRB.super::xs_B_;
        assertEquals(q.m("*"), "_B_xsB:*");
    }

}
