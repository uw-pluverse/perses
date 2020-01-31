



import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;



@Test
public class MethodReferenceTestNewInnerImplicitArgs {


    static class S {
        String b;
        S(String s, String s2) { b = s + s2; }
    }

    interface I {
        S m();
    }

    interface I2 {
        S m(int i, int j);
    }

    public static void testConstructorReferenceImplicitParameters() {
        String title = "Hey";
        String a2 = "!!!";
        class MS extends S {
            MS() {
                super(title, a2);
            }
        }

        I result = MS::new;
        assertEquals(result.m().b, "Hey!!!");

        class MS2 extends S {
            MS2(int x, int y) {
                super(title+x, a2+y);
            }
        }

        I2 result2 = MS2::new;
        assertEquals(result2.m(8, 4).b, "Hey8!!!4");
    }
}
