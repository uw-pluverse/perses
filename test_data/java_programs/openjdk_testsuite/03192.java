



import static org.testng.Assert.assertEquals;
import org.testng.annotations.Test;

@Test
public class InnerConstructor  {

    public void testLambdaWithInnerConstructor() {
        assertEquals(seq1().m().toString(), "Cbl:nada");
        assertEquals(seq2().m("rats").toString(), "Cbl:rats");
    }

    Ib1 seq1() {
        return () -> { return new Cbl(); };
    }

    Ib2 seq2() {
        return (x) -> { return new Cbl(x); };
    }

    class Cbl {
        String val;

        Cbl() {
            this.val = "nada";
        }

        Cbl(String z) {
            this.val = z;
        }

        public String toString() {
            return "Cbl:" + val;
        }
    }

    interface Ib1 {
        Object m();
    }

    interface Ib2 {
        Object m(String x);
    }
}
