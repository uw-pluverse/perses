

interface i1 {}
interface i2 {}

public class OrderedIntersections {
    static <t1 extends i1 & i2> Object smf(t1 x) {
        System.out.println( " smf1 " );
        return null;
    }

    static <t2 extends i2 & i1> Object smf(t2 x) {
        System.out.println( " smf2 " );
        return null;
    }
}
