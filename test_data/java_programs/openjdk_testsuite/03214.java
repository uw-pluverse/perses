



import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;



@Test
public class MethodReferenceTestInnerInstance {

    public void testMethodReferenceInnerInstance() {
        cia().cib().testMethodReferenceInstance();
    }

    public void testMethodReferenceInnerExternal() {
        cia().cib().testMethodReferenceExternal();
    }

    interface SI {
        String m(Integer a);
    }

    class CIA {

        String xI(Integer i) {
            return "xI:" + i;
        }

        public class CIB {

            public void testMethodReferenceInstance() {
                SI q;

                q = CIA.this::xI;
                assertEquals(q.m(55), "xI:55");
            }

            public void testMethodReferenceExternal() {
                SI q;

                q = (new E())::xI;
                assertEquals(q.m(77), "ExI:77");
            }
        }

        CIB cib() {
            return new CIB();
        }

        class E {

            String xI(Integer i) {
                return "ExI:" + i;
            }
        }

    }

    CIA cia() {
        return new CIA();
    }
}
