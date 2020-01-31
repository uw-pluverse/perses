



import static org.testng.Assert.assertEquals;
import org.testng.annotations.Test;

interface LTII {

    interface ILsp1 {
        String m();
    }

    interface ILsp2 {
        String m(String x);
    }

    default ILsp1 t1() {
        return () -> { return "yo"; };
    }

    default ILsp2 t2() {
        return (x) -> { return "snur" + x; };
    }

}

@Test
public class InInterface implements LTII {

    public void testLambdaInDefaultMethod() {
        assertEquals(t1().m(), "yo");
        assertEquals(t2().m("p"), "snurp");
    }

}
