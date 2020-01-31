



import java.util.*;

class CastTest {

    

    private class BA<T> { }
    private class BB<T, S> { }

    private class BC<T> extends BA<Integer> { }
    private class BD<T> extends BB<T, T> { }

    private void inconsistentMatches() {
        Object o;

        o = (BD<String>) (BB<Number, String>) null; 
    }

}
