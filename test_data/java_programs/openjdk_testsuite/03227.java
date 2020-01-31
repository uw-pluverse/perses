



import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;



interface SPRI { String m(String a); }

class SPRA {
    String xsA__(String s) {
        return "A__xsA:" + s;
    }

    String xsA_M(String s) {
        return "A_MxsA:" + s;
    }

    String xsAB_(String s) {
        return "AB_xsA:" + s;
    }

    String xsABM(String s) {
        return "ABMxsA:" + s;
    }

}

class SPRB extends SPRA {

    String xsAB_(String s) {
        return "AB_xsB:" + s;
    }

    String xsABM(String s) {
        return "ABMxsB:" + s;
    }

    String xs_B_(String s) {
        return "_B_xsB:" + s;
    }

    String xs_BM(String s) {
        return "_BMxsB:" + s;
    }

}

@Test
public class MethodReferenceTestSuper extends SPRB {

    String xsA_M(String s) {
        return "A_MxsM:" + s;
    }


    String xsABM(String s) {
        return "ABMxsM:" + s;
    }

    String xs_BM(String s) {
        return "_BMxsM:" + s;
    }

    public void testMethodReferenceSuper() {
        SPRI q;

        q = super::xsA__;
        assertEquals(q.m("*"), "A__xsA:*");

        q = super::xsA_M;
        assertEquals(q.m("*"), "A_MxsA:*");

        q = super::xsAB_;
        assertEquals(q.m("*"), "AB_xsB:*");

        q = super::xsABM;
        assertEquals(q.m("*"), "ABMxsB:*");

        q = super::xs_B_;
        assertEquals(q.m("*"), "_B_xsB:*");

        q = super::xs_BM;
        assertEquals(q.m("*"), "_BMxsB:*");
    }

}
