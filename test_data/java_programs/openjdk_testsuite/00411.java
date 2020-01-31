



import java.util.*;

class CastTest {

    

    private interface DA<T> { }
    private interface DB<T> extends DA<T> { }
    private interface DC<T> extends DA<Integer> { }

    private <N extends Number, I extends Integer, R extends Runnable, S extends String> void disjointness() {
        Object o;

        o = (DA<S>) (DA<R>) null; 
    }

}
